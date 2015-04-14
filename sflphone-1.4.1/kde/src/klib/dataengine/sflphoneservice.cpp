/****************************************************************************
 *   Copyright (C) 2009-2014 by Savoir-Faire Linux                          *
 *   Author : Jérémy Quentin <jeremy.quentin@savoirfairelinux.com>          *
 *            Emmanuel Lepage Vallee <emmanuel.lepage@savoirfairelinux.com> *
 *                                                                          *
 *   This library is free software; you can redistribute it and/or          *
 *   modify it under the terms of the GNU Lesser General Public             *
 *   License as published by the Free Software Foundation; either           *
 *   version 2.1 of the License, or (at your option) any later version.     *
 *                                                                          *
 *   This library is distributed in the hope that it will be useful,        *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU      *
 *   Lesser General Public License for more details.                        *
 *                                                                          *
 *   You should have received a copy of the GNU General Public License      *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.  *
 ***************************************************************************/

#include "sflphoneservice.h"

#include "../../lib/call.h"
#include "../../lib/account.h"
#include "../../lib/dbus/callmanager.h"


/*****************************************************************************
 *                                                                           *
 *                                    Jobs                                   *
 *                                                                           *
 ****************************************************************************/

///Constructor
CallJob::CallJob(QObject* parent, const QString& operation, const QVariantMap& parameters)
   : Plasma::ServiceJob("", operation, parameters, parent)
   , m_pAccount ( Account::buildExistingAccountFromId(parameters[ "AccountId" ].toString() ))
   , m_Number   ( parameters[ "Number"    ].toString() )
{
   
}

///Make a call
void CallJob::start()
{
   Call* call = SFLPhoneEngine::getModel()->dialingCall(m_Number,m_pAccount);
   if (call) {
      call->setDialNumber(m_Number);
      call->performAction(Call::Action::ACCEPT);
   }
}


///Constructor
DTMFJob::DTMFJob(QObject* parent, const QString& operation, const QVariantMap& parameters)
   : Plasma::ServiceJob("", operation, parameters, parent)
   , m_mStr( parameters[ "str" ].toString() )
{
   
}

///Play a DMTF tone
void DTMFJob::start()
{
   CallManagerInterface& callManager = DBus::CallManager::instance();
   Q_NOREPLY callManager.playDTMF(m_mStr);
}


///Constructor
HangUpJob::HangUpJob(QObject* parent, const QString& operation, const QVariantMap& parameters)
   : Plasma::ServiceJob("", operation, parameters, parent)
   , m_CallId( parameters[ "callid" ].toString() )
{
   
}

///Hang up a call
void HangUpJob::start()
{
   Call* call = SFLPhoneEngine::getModel()->getCall(m_CallId);
   call->performAction(Call::Action::REFUSE);
   call->changeCurrentState(Call::State::OVER);
}


///Constructor
TransferJob::TransferJob(QObject* parent, const QString& operation, const QVariantMap& parameters)
   : Plasma::ServiceJob("", operation, parameters, parent)
   , m_CallId         ( parameters[ "callid" ].toString()         )
   , m_transferNumber ( parameters[ "transfernumber" ].toString() )
{
   
}


///Transfer a call
void TransferJob::start()
{
   Call* call = SFLPhoneEngine::getModel()->getCall(m_CallId);
   call->setTransferNumber(m_transferNumber);
   call->changeCurrentState( Call::State::TRANSFERRED );
   call->actionPerformed   ( Call::Action::ACCEPT                  );
   call->changeCurrentState( Call::State::OVER        );
}

///Constructor
HoldJob::HoldJob(QObject* parent, const QString& operation, const QVariantMap& parameters)
   : Plasma::ServiceJob("", operation, parameters, parent)
   , m_CallId         ( parameters[ "callid" ].toString() )
{}


///Put a call on hold
void HoldJob::start()
{
   Call* call = SFLPhoneEngine::getModel()->getCall(m_CallId);
   call->performAction(Call::Action::HOLD);
}

///Constructor
RecordJob::RecordJob(QObject* parent, const QString& operation, const QVariantMap& parameters)
   : Plasma::ServiceJob("", operation, parameters, parent)
   , m_CallId         ( parameters[ "callid" ].toString() )
{
   
}


///Record a call
void RecordJob::start()
{
   Call* call = SFLPhoneEngine::getModel()->getCall(m_CallId);
   call->performAction(Call::Action::RECORD);
}


/*****************************************************************************
 *                                                                           *
 *                        Service related functions                          *
 *                                                                           *
 ****************************************************************************/

///Constructor
SFLPhoneService::SFLPhoneService(SFLPhoneEngine *engine):m_engine(engine)
{
    setName("sflphone");
}

///Constructor
ServiceJob *SFLPhoneService::createJob(const QString &operation, QMap<QString, QVariant> &parameters)
{
   if (!m_engine)
      return 0;

   /*                   RPC NAME                                   JOB                          */
   /**/if      (operation == "Call"     ) { return new CallJob    ( this, operation,parameters); }
   /**/else if (operation == "DMTF"     ) { return new DTMFJob    ( this, operation,parameters); }
   /**/else if (operation == "Transfer" ) { return new TransferJob( this, operation,parameters); }
   /**/else if (operation == "Hangup"   ) { return new HangUpJob  ( this, operation,parameters); }
   /**/else if (operation == "Hold"     ) { return new HoldJob    ( this, operation,parameters); }
   /**/else if (operation == "Record"   ) { return new RecordJob  ( this, operation,parameters); }
   /*                                                                                           */

   m_engine->setData(operation, parameters["query"]);
   return 0;
}
