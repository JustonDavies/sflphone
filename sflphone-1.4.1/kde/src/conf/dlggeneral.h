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

#ifndef DLGGENERAL_H
#define DLGGENERAL_H

#include <QWidget>
#include <kconfigdialog.h>

#include "ui_dlggeneralbase.h"

/**
	@author Jérémy Quentin <jeremy.quentin@gmail.com>
*/
class DlgGeneral : public QWidget, public Ui_DlgGeneralBase
{
Q_OBJECT
public:
   //Constructor
   explicit DlgGeneral(KConfigDialog *parent = nullptr);

   //Destructor
   ~DlgGeneral();

   bool hasChanged();
   bool m_HasChanged;

public Q_SLOTS:
   //Mutator
   void updateWidgets();
   void updateSettings();
   void slotClearCallHistoryAsked();

public Q_SLOTS:
   void changed();

Q_SIGNALS:
   ///Emitted when the buttons need to be updated
   void updateButtons();
   void clearCallHistoryAsked();

};

#endif
