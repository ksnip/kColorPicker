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

	explicit KColorPickerPrivate(KColorPicker *kColorPicker, bool showAlphaChannel = false, QWidget *parent = nullptr);

	KColorPicker *const q_ptr;
	QSize mIconSize;
	PopupMenu *mPopupMenu;
	QColor mSelectedColor;
};

KColorPicker::KColorPicker(bool showAlphaChannel, QWidget *parent) : d_ptr(new KColorPickerPrivate(this, showAlphaChannel, parent))
{
	// Default Colors
	resetColors(showAlphaChannel);
}

KColorPicker::~KColorPicker()
{}

void KColorPicker::setColor(const QColor &color)
{
	Q_D(KColorPicker);
	d->mSelectedColor = color;
	setColorIcon(color);
	d->mPopupMenu->selectColor(color);
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

void KColorPicker::resetColors(bool showAlphaChannel)
{
	Q_D(const KColorPicker);
	d->mPopupMenu->removeColors();

	d->mPopupMenu->addColor(QColor(Qt::red));
	d->mPopupMenu->addColor(QColor(Qt::green));
	d->mPopupMenu->addColor(QColor(Qt::blue));
	d->mPopupMenu->addColor(QColor(Qt::yellow));
	d->mPopupMenu->addColor(QColor(Qt::magenta));
	d->mPopupMenu->addColor(QColor(Qt::cyan));
	d->mPopupMenu->addColor(QColor(Qt::white));
	d->mPopupMenu->addColor(QColor(Qt::black));

	if(showAlphaChannel) {
		d->mPopupMenu->addColor(QColor(0, 255, 255, 100));
		d->mPopupMenu->addColor(QColor(255, 0, 255, 100));
		d->mPopupMenu->addColor(QColor(255, 255, 0, 100));
		d->mPopupMenu->addColor(QColor(255, 255, 255, 100));
	}
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

KColorPickerPrivate::KColorPickerPrivate(KColorPicker *kColorPicker, bool showAlphaChannel, QWidget *parent) :
	q_ptr(kColorPicker),
	mPopupMenu(new PopupMenu(showAlphaChannel, parent))
{
	initResource();

	mIconSize = QSize(25, 25);
	kColorPicker->setPopupMode(QToolButton::InstantPopup);
	kColorPicker->setMenu(mPopupMenu);
	kColorPicker->connect(mPopupMenu, &PopupMenu::colorChanged, kColorPicker, &KColorPicker::colorSelected);
}

} // namespace kColorPicker
