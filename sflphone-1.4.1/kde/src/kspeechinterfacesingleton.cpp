/***************************************************************************
 *   Copyright (C) 2009-2014 by Savoir-Faire Linux                         *
 *   Author : Emmanuel Lepage Vallee <emmanuel.lepage@savoirfairelinux.com>*
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 **************************************************************************/
#include "kspeechinterfacesingleton.h"

#include <QtDBus/QDBusConnection>
#include <KSpeech>

OrgKdeKSpeechInterface* KSpeechInterfaceSingleton::m_pInstance = 0;

OrgKdeKSpeechInterface* KSpeechInterfaceSingleton::instance() {
   if (!m_pInstance) {
      m_pInstance = new OrgKdeKSpeechInterface( "org.kde.kttsd", "/KSpeech", QDBusConnection::sessionBus());
      m_pInstance->setApplicationName("SFLPhone KDE");
   }
   return m_pInstance;
}
