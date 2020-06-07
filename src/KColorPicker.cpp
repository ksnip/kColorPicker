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

#include <kColorPicker/KColorPicker.h>

#include "IconCreator.h"
#include "PopupMenu.h"

inline void initResource()
{
	Q_INIT_RESOURCE(kColorPicker_icons);
}

namespace kColorPicker {

class KColorPickerPrivate
{
	Q_DISABLE_COPY(KColorPickerPrivate)

	Q_DECLARE_PUBLIC(KColorPicker)

	explicit KColorPickerPrivate(KColorPicker *kColorPicker);

	KColorPicker *const q_ptr;
	QSize mIconSize;
	PopupMenu mPopupMenu;
	QColor mSelectedColor;
};

KColorPicker::KColorPicker() : d_ptr(new KColorPickerPrivate(this))
{}

KColorPicker::~KColorPicker()
{}

void KColorPicker::setColor(const QColor &color)
{
	Q_D(KColorPicker);
	d->mSelectedColor = color;
	setColorIcon(color);
	d->mPopupMenu.selectColor(color);
}

void KColorPicker::colorSelected(const QColor &color)
{
	Q_D(KColorPicker);
	d->mSelectedColor = color;
	setColorIcon(color);
	emit colorChanged(color);
}

void KColorPicker::setFixedSize(const QSize &size)
{
	Q_D(const KColorPicker);
	QToolButton::setFixedSize(size);
	setIconSize(size);
	setColorIcon(d->mSelectedColor);
}

void KColorPicker::setFixedSize(int width, int height)
{
	Q_D(const KColorPicker);
	QToolButton::setFixedSize(width, height);
	setIconSize(QSize(width, height));
	setColorIcon(d->mSelectedColor);
}

QColor KColorPicker::color() const
{
	Q_D(const KColorPicker);
	return d->mSelectedColor;
}

void KColorPicker::setIconSize(const QSize &size)
{
	Q_D(KColorPicker);
	auto scaleFactor = 0.6;
	d->mIconSize = size * scaleFactor;
	QToolButton::setIconSize(d->mIconSize);
}

void KColorPicker::setColorIcon(const QColor &color)
{
	Q_D(KColorPicker);
	auto icon = IconCreator::createIcon(color, d->mIconSize);
	setIcon(icon);
	setToolTip(color.name());
}

//
// KColorPickerPrivate
//

KColorPickerPrivate::KColorPickerPrivate(KColorPicker *kColorPicker) : q_ptr(kColorPicker)
{
	initResource();

	mIconSize = QSize(25, 25);
	kColorPicker->setPopupMode(QToolButton::InstantPopup);
	kColorPicker->setMenu(&mPopupMenu);
	kColorPicker->connect(&mPopupMenu, &PopupMenu::colorChanged, kColorPicker, &KColorPicker::colorSelected);

	// Default Colors
	mPopupMenu.addColor(QColor(Qt::red));
	mPopupMenu.addColor(QColor(Qt::green));
	mPopupMenu.addColor(QColor(Qt::blue));
	mPopupMenu.addColor(QColor(Qt::yellow));
	mPopupMenu.addColor(QColor(Qt::magenta));
	mPopupMenu.addColor(QColor(Qt::cyan));
	mPopupMenu.addColor(QColor(Qt::white));
	mPopupMenu.addColor(QColor(Qt::black));

}

} // namespace kColorPicker
