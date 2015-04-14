/****************************************************************************
 *   Copyright (C) 2010-2014 by Savoir-Faire Linux                          *
 *   Author : Emmanuel Lepage Vallee <emmanuel.lepage@savoirfairelinux.com> *
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
#ifndef SFLPHONE_SERVICE_H
#define SFLPHONE_SERVICE_H

#include "sflphoneengine.h"

#include <Plasma/Service>
#include <Plasma/ServiceJob>

#include "../../lib/call.h"
#include "../../lib/callmodel.h"

using namespace Plasma;

class Account;

///SFLPhoneService: RPC between the plasmoid and the library
class SFLPhoneService : public Plasma::Service
{
   Q_OBJECT

public:
   explicit SFLPhoneService(SFLPhoneEngine *engine);
   ServiceJob *createJob(const QString &operation, QMap<QString, QVariant> &parameters);

private:
   SFLPhoneEngine *m_engine;
};

///CallJob: Call using and account and a number
class CallJob : public Plasma::ServiceJob
{
   Q_OBJECT
public:
   CallJob(    QObject* parent, const QString& operation, const QVariantMap& parameters = QVariantMap());

   void start();

private:
    Account* m_pAccount;
    QString  m_Number  ;
};

///DTMFJob: Play a sound when called
class DTMFJob : public Plasma::ServiceJob
{
   Q_OBJECT
public:
   DTMFJob(    QObject* parent, const QString& operation, const QVariantMap& parameters = QVariantMap());

   void start();
private:
   QString m_mStr;
};

///HangUpJob: Hang up a call using an id
class HangUpJob : public Plasma::ServiceJob
{
   Q_OBJECT
public:
   HangUpJob(  QObject* parent, const QString& operation, const QVariantMap& parameters = QVariantMap());

   void start();
private:
   QString m_CallId;
};

///TransferJob: Transfer a call
class TransferJob : public Plasma::ServiceJob
{
   Q_OBJECT
public:
   TransferJob(QObject* parent, const QString& operation, const QVariantMap& parameters = QVariantMap());

   void start();
private:
   QString m_CallId        ;
   QString m_transferNumber;
};

///HoldJob: Put or remove a call from hold mode
class HoldJob : public Plasma::ServiceJob
{
   Q_OBJECT
public:
   HoldJob(    QObject* parent, const QString& operation, const QVariantMap& parameters = QVariantMap());

   void start();
private:
   QString m_CallId;
};

///RecordJob: Record a call
class RecordJob : public Plasma::ServiceJob
{
   Q_OBJECT
public:
   RecordJob(  QObject* parent, const QString& operation, const QVariantMap& parameters = QVariantMap());

   void start();
private:
   QString m_CallId;
};


#endif //SFLPHONE_SERVICE_H
