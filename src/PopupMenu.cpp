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

#include "PopupMenu.h"

PopupMenu::PopupMenu()
{
    mButtonGroup = new QButtonGroup();
    mLayout = new QGridLayout();
    setLayout(mLayout);
}

PopupMenu::~PopupMenu()
{
    delete mButtonGroup;
}

void PopupMenu::addColor(const QColor &color)
{
    if(!isColorInGrid(color)) {
        addColorToGrid(color);
    }
}

void PopupMenu::generateGrid()
{
    auto row = 0;
    auto column = 0;

    clearGrid();

    for(auto button : mColorButtons) {
        mLayout->addWidget(button, row, column % 4);
        column++;
        if(column % 4 == 0) {
            row++;
        }
    }
}

ColorButton *PopupMenu::createButton(const QColor &color)
{
    IconCreator iconCreator;
    auto icon = iconCreator.createIcon(color);
    auto button = new ColorButton(icon, color);
    return button;
}

void PopupMenu::addColorToGrid(const QColor &color)
{
    auto button = createButton(color);
    mButtonGroup->addButton(button);
    mColorButtons.append(button);
    connect(button, &AbstractPopupMenuButton::colorSelected, this, &PopupMenu::colorSelected);
    generateGrid();
}

void PopupMenu::clearGrid()
{
    for(auto button : mColorButtons) {
        mLayout->removeWidget(button);
    }
}

bool PopupMenu::isColorInGrid(const QColor &color)
{
    for(auto button : mColorButtons) {
        if(button->color() == color) {
            return true;
        }
    }

    return false;
}

void PopupMenu::colorSelected(const QColor &color)
{
    emit colorChanged(color);
    hide();
}
