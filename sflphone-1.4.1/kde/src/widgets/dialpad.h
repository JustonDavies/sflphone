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
#ifndef DIALPAD_H
#define DIALPAD_H

#include <QWidget>
#include <QPushButton>

//Qt
class QGridLayout;

///DialpadButton: the 12 button of the dialpad
class DialpadButton : public QPushButton
{
   Q_OBJECT
public:
   ///Constructor
   DialpadButton(QWidget* parent, const QString& value): QPushButton(parent),m_Value(value) {
      setContentsMargins(0,0,0,0);
      connect(this,SIGNAL(clicked()),this,SLOT(sltClicked()));
   }
private Q_SLOTS:
   ///Called on button click
   void sltClicked() { emit typed(m_Value); }
private:
   QString m_Value;
Q_SIGNALS:
   ///Emitted to add a number/letter to the string
   void typed(QString&);
};


///Dialpad: A widget that representing a phone dialpad with associated numbers and letters
class Dialpad : public QWidget
{
Q_OBJECT

private:
   //Attributes
   QGridLayout*    gridLayout;
   DialpadButton** m_pButtons;

   static const char* m_pNumbers[];
   static const char* m_pTexts  [];
   static const int   m_Spacing    = 5  ;
   static const int   m_NumberSize = 14 ;
   static const int   m_TextSize   = 8  ;

public:
    explicit Dialpad(QWidget *parent = nullptr);
    ~Dialpad();

private Q_SLOTS:
   void clicked(QString& text);

Q_SIGNALS:
   ///Emitted to add a number/letter to the string
   void typed(const QString &text);
};

#endif
