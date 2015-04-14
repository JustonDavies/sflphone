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

//Parent
#include "sflphonetray.h"

//Qt
#include <QtGui/QMenu>
#include <QtGui/QIcon>

//KDE
#include <KDebug>
#include <KAction>

///Constructor
SFLPhoneTray::SFLPhoneTray(const QIcon &icon, QWidget *parent)
      : KSystemTrayIcon(icon, parent),
         m_pTrayIconMenu(0)
{
   m_pTrayIconMenu = new QMenu(parentWidget());
   setContextMenu(m_pTrayIconMenu);
}

///Destructor
SFLPhoneTray::~SFLPhoneTray()
{
   delete m_pTrayIconMenu;
}


/*****************************************************************************
 *                                                                           *
 *                                  Mutator                                  *
 *                                                                           *
 ****************************************************************************/

///Add a new action
void SFLPhoneTray::addAction(KAction *action)
{
   m_pTrayIconMenu->addAction(action);
}

///Add a menu separator
void SFLPhoneTray::addSeparator()
{
   m_pTrayIconMenu->addSeparator();
}
