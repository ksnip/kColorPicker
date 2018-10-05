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

namespace kColorPicker {

AbstractPopupMenuButton::AbstractPopupMenuButton(const QIcon &icon)
{
    setIcon(icon);
	setFixedSize(iconSize() + QSize(4,4));
    connect(this, &QToolButton::clicked, this, &AbstractPopupMenuButton::buttonClicked);
}

void AbstractPopupMenuButton::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QStyleOption styleOption;
	styleOption.initFrom(this);
	auto buttonRect = event->rect();
	auto selectionRect = QRect(buttonRect.topLeft().x(), buttonRect.topLeft().y(), iconSize().width() + 3, iconSize().height() + 3);
	auto hoverRect = QRect(buttonRect.topLeft().x() + 1, buttonRect.topLeft().y() + 1, iconSize().width() + 1, iconSize().height() + 1);

	painter.drawPixmap(buttonRect.topLeft() + QPointF(2, 2), icon().pixmap(iconSize()));

	if(isChecked()) {
		painter.drawRect(selectionRect);
	}
	
	if(styleOption.state & QStyle::State_MouseOver)
	{
		painter.setPen(QColor(QStringLiteral("#add8e6")));
		painter.drawRect(hoverRect);
	}
}

} // namespace kColorPicker
