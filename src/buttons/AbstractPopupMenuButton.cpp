/*
 * Copyright (C) 2018 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "AbstractPopupMenuButton.h"

AbstractPopupMenuButton::AbstractPopupMenuButton(const QIcon &icon)
{
    setIcon(icon);
    setStyleSheet(getStyle());
    connect(this, &QToolButton::clicked, this, &AbstractPopupMenuButton::buttonClicked);
}

QString AbstractPopupMenuButton::getStyle() const
{
    return QStringLiteral("QToolButton { "
                              "border: 0px; "
                              "margin: 2px;"
                              "padding-right: -1px; "
                              "padding-bottom: -1px; }"
                          "QToolButton:checked { "
                              "margin: 1px ; "
                              "border: 1px double black; }"
                          "QToolButton:hover { "
                              "border: 1px solid lightblue; }"
                          );
}
