/*
* Copyright (C) 2020 Tianjin KYLIN Information Technology Co., Ltd.
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
#include "screenshotwidget.h"

screenshotWidget::screenshotWidget(QWidget *parent) : QWidget(parent)
{
    initMemberVariables();
    initLayout();
}

screenshotWidget::~screenshotWidget()
{

}

void screenshotWidget::initMemberVariables()
{
    m_pWidgetButton         = new QWidget();
    m_pWidgetButton->setFixedSize(56, 56);
    m_pWidgetButton->setContentsMargins(0, 0, 0, 0);
    m_pVboxButtonLayout     = new QVBoxLayout();
    m_pVboxButtonLayout->setContentsMargins(0, 0, 0, 0);

    m_pscreenshotButton = new QPushButton();
    m_pscreenshotButton->setIcon(QIcon::fromTheme(KYLIN_SCREENSHOT_NORMAL_NAME, QIcon(KYLIN_SCREENSHOT_NORMAL_PATH)));
    m_pscreenshotButton->setFixedSize(56, 56);
    m_pscreenshotButton->setIconSize(QSize(32, 32));
    m_pStyleNormal = new customstyle_switchNormalStatus("ukui-default");
    m_pscreenshotButton->setStyle(m_pStyleNormal);
    connect(m_pscreenshotButton, &switchButton::clicked, this, &screenshotWidget::sreenShotButtonClickedSlots);

    m_pscreenshotlabel = new QLabel(QObject::tr("截图"));
    m_pscreenshotlabel->setAlignment(Qt::AlignHCenter);

    m_pVboxLayout = new QVBoxLayout();
    m_pVboxLayout->setContentsMargins(0, 0, 0, 0);
    m_pVboxLayout->setSpacing(0);

    this->setFixedSize(56, 78);
    this->setContentsMargins(0, 0, 0, 0);
    return;
}

void screenshotWidget::initLayout()
{
    m_pVboxButtonLayout->addWidget(m_pscreenshotButton, 0, Qt::AlignCenter);
    m_pWidgetButton->setLayout(m_pVboxButtonLayout);
    m_pVboxLayout->addWidget(m_pWidgetButton, 0, Qt::AlignCenter);
    m_pVboxLayout->addItem(new QSpacerItem(15, 4));
    m_pVboxLayout->addWidget(m_pscreenshotlabel);
    this->setLayout(m_pVboxLayout);
    return;
}

void screenshotWidget::sreenShotButtonClickedSlots()
{
    QProcess p(0);
    p.startDetached("gnome-screenshot -a");
    p.waitForStarted();
    return;
}