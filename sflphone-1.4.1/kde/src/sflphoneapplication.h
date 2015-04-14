/***************************************************************************
 *   Copyright (C) 2009-2014 by Savoir-Faire Linux                         *
 *   Author : Jérémy Quentin <jeremy.quentin@savoirfairelinux.com>         *
 *            Emmanuel Lepage Vallee <emmanuel.lepage@savoirfairelinux.com>*
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

#ifndef SFLPHONEAPPLICATION_H
#define SFLPHONEAPPLICATION_H

#include <KUniqueApplication>
#include <QDBusAbstractAdaptor>

//Qt
class QEvent;

//SFLPhone
class SFLPhone;

///SFLPhoneApplication: Main application
class SFLPhoneApplication : 
#ifdef DISABLE_UNIQUE_APPLICATION
   public KApplication
#else
   public KUniqueApplication
#endif
{
  Q_OBJECT

public:
   // Constructor
   SFLPhoneApplication();

   // Destructor
   virtual ~SFLPhoneApplication();

   // Manage new instances
   virtual int newInstance();

   // Exit gracefully
   virtual bool notify (QObject* receiver, QEvent* e);

private:
   //Init
   void initializeMainWindow();
   void initializePaths();
};

#endif // SFLPHONEAPPLICATION_H
