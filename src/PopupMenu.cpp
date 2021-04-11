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

#include "PopupMenu.h"

namespace kColorPicker {

PopupMenu::PopupMenu() :
	mButtonGroup(new QButtonGroup()),
	mLayout(new QGridLayout()),
	mColorDialogButton(new ColorDialogButton(QIcon(QLatin1String(":/icons/ellipsis"))))
{

	mLayout->setSpacing(0);
	mLayout->setMargin(5);
	setLayout(mLayout);

	connect(mColorDialogButton, &AbstractPopupMenuButton::colorSelected, this, &PopupMenu::colorSelected);
}

PopupMenu::~PopupMenu()
{
	delete mButtonGroup;
	delete mColorDialogButton;
}

void PopupMenu::addColor(const QColor &color)
{
	if (!isColorInGrid(color)) {
		addColorButton(color);
	}
}

void PopupMenu::selectColor(const QColor &color)
{
	addColor(color);

	for (auto button : mColorButtons) {
		if (button->color() == color) {
			button->setChecked(true);
			return;
		}
	}
}

void PopupMenu::generateGrid()
{
	auto row = 0;
	auto column = 0;

	clearGrid();

	for (auto button : mColorButtons) {
		mLayout->addWidget(button, row, column % 4);
		column++;
		if (column % 4 == 0) {
			row++;
		}
	}

	mLayout->addWidget(mColorDialogButton, row, column % 4);
}

ColorButton *PopupMenu::createButton(const QColor &color)
{
	auto icon = IconCreator::createIcon(color, ScaledSizeProvider::scaledSize(QSize(25, 25)));
	auto button = new ColorButton(icon, color);
	return button;
}

void PopupMenu::addColorButton(const QColor &color)
{
	auto button = createButton(color);
	mButtonGroup->addButton(button);
	mColorButtons.append(button);
	connect(button, &AbstractPopupMenuButton::colorSelected, this, &PopupMenu::colorSelected);
	generateGrid();
}

void PopupMenu::clearGrid()
{
	for (auto button : mColorButtons) {
		mLayout->removeWidget(button);
	}
}

bool PopupMenu::isColorInGrid(const QColor &color)
{
	for (auto button : mColorButtons) {
		if (button->color() == color) {
			return true;
		}
	}
	return false;
}

void PopupMenu::colorSelected(const QColor &color)
{
	emit colorChanged(color);
	selectColor(color);
	hide();
}

QSize PopupMenu::sizeHint() const
{
	return mLayout->sizeHint();
}

} // namespace kColorPicker