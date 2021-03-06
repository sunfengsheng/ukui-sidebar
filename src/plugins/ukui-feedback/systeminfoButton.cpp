/*
* Copyright (C) 2019 Tianjin KYLIN Information Technology Co., Ltd.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3, or (at your option)
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, see <http://www.gnu.org/licenses/&gt;.
*
*/
#include"systeminfoButton.h"
#include "ukuiFeedback.h"
#include <QPointF>


systeminfo_button::systeminfo_button(QWidget* parent) :QPushButton(parent)
{

}

systeminfo_button::~systeminfo_button()
{

}

void systeminfo_button::enterEvent(QEvent *e)
{
    QPointF position = QCursor::pos();
    pfeedback->systeminfo_show(position);
    pfeedback->setFocus();
}

void systeminfo_button::leaveEvent(QEvent *e)
{
    pfeedback->systeminfo_hide();
}

void systeminfo_button::setFeedBack(feedback *p)
{
    pfeedback = p;
}


