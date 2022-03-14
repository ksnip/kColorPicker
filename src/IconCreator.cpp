/*
 * Copyright (C) 2018 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
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

#include "IconCreator.h"

namespace kColorPicker {

QIcon IconCreator::createIcon(const QColor &color, const QSize &size)
{
	auto background = getBackgroundBrush(size);

	QPixmap pixmap(size);
	QPainter painter(&pixmap);

	// Paint background
	painter.setPen(Qt::NoPen);
	painter.setBrush(background);
	painter.drawRect(0, 0, size.width(), size.height());

	// Paint color
	painter.setBrush(color);
	painter.drawRect(0, 0, size.width(), size.height());

	// Paint border
    auto penWidth = painter.pen().width();
    painter.setPen(QColor(Qt::gray));
    painter.drawRect(0, 0, size.width() - penWidth, size.height() - penWidth);

    return { pixmap };
}

QImage IconCreator::getBackgroundBrush(const QSize &size)
{
	auto halfWidth = size.width() / 2;
	auto halfHeight = size.height() / 2;
	auto background = QImage(size, QImage::Format_ARGB32_Premultiplied);
	background.fill(Qt::white);
	QPainter painter(&background);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::gray);
	painter.drawRect(0, 0, halfWidth, halfHeight);
	painter.drawRect(halfWidth, halfHeight, size.width(), size.height());

	return background;
}

} // namespace kColorPicker