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

#include "ColorDialogButton.h"

namespace kColorPicker {

ColorDialogButton::ColorDialogButton(const QIcon &icon, bool showAlphaChannel) :
	AbstractPopupMenuButton(icon),
	mShowAlphaChannel(showAlphaChannel)
{
    setCheckable(false);
}

void ColorDialogButton::buttonClicked()
{
    auto color = QColorDialog::getColor(Qt::white, this, QString(), getColorDialogOptions());
    emit colorSelected(color);
}

QFlags<QColorDialog::ColorDialogOption> ColorDialogButton::getColorDialogOptions() const
{
	return mShowAlphaChannel ? QColorDialog::ShowAlphaChannel : QFlags<QColorDialog::ColorDialogOption>();
}

} // namespace kColorPicker