/*
 *  Copyright (C) 2014 Savoir-Faire Linux Inc.
 *  Author: Vittorio Giovara <vittorio.giovara@savoirfairelinux.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  Additional permission under GNU GPL version 3 section 7:
 *
 *  If you modify this program, or any covered work, by linking or
 *  combining it with the OpenSSL project's OpenSSL library (or a
 *  modified version of that library), containing parts covered by the
 *  terms of the OpenSSL or SSLeay licenses, Savoir-Faire Linux Inc.
 *  grants you additional permission to convey the resulting work.
 *  Corresponding Source for a non-source form of such a combination
 *  shall include the source code for the parts of OpenSSL used as well
 *  as that of the covered work.
 */

#warning Using a stub file will produce a non working application

#include "client/callmanager.h"

CallManager::CallManager()
{}

void CallManager::callStateChanged(const std::string& callID,
                                   const std::string& state)
{
}

void CallManager::transferFailed()
{
}

void CallManager::transferSucceeded()
{
}

void CallManager::recordPlaybackStopped(const std::string& path)
{
}

void CallManager::voiceMailNotify(const std::string& callID,
                                  const int32_t& nd_msg)
{
}

void CallManager::incomingMessage(const std::string& ID,
                                  const std::string& from,
                                  const std::string& msg)
{
}

void CallManager::incomingCall(const std::string& accountID,
                               const std::string& callID,
                               const std::string& from)
{
}

void CallManager::recordPlaybackFilepath(const std::string& id,
                                         const std::string& filename)
{
}

void CallManager::conferenceCreated(const std::string& confID)
{
}

void CallManager::conferenceChanged(const std::string& confID,
                                    const std::string& state)
{
}

void CallManager::conferenceRemoved(const std::string& confID)
{
}

void CallManager::newCallCreated(const std::string& accountID,
                                 const std::string& callID,
                                 const std::string& to)
{
}

void CallManager::sipCallStateChanged(const std::string& accoundID,
                                      const std::string& state,
                                      const int32_t& code)
{
}

void CallManager::recordingStateChanged(const std::string& callID,
                                        const bool& state)
{
}

void CallManager::updatePlaybackScale(const std::string& callID,
                                      const int32_t&,
                                      const int32_t&)
{
}

void CallManager::secureSdesOn(std::string const& callID)
{
}

void CallManager::secureSdesOff(std::string const& callID)
{
}

void CallManager::secureZrtpOn(const std::string& callID,
                               const std::string& cipher)
{
}

void CallManager::secureZrtpOff(const std::string& callID)
{
}

void CallManager::showSAS(const std::string& callID,
                          const std::string& sas,
                          const bool& verified)
{
}

void CallManager::zrtpNotSuppOther(const std::string& callID)
{
}

void CallManager::zrtpNegotiationFailed(const std::string& callID,
                                        const std::string& reason,
                                        const std::string& severity)
{
}

void CallManager::onRtcpReportReceived(const std::string& callID,
                                       const std::map<std::string, int>& stats)
{
}
