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

#ifndef KCOLORPICKER_POPUPMENU_H
#define KCOLORPICKER_POPUPMENU_H

#include <QMenu>
#include <QGridLayout>
#include <QButtonGroup>

#include "IconCreator.h"
#include "buttons/AbstractPopupMenuButton.h"

class PopupMenu : public QMenu
{
public:
    PopupMenu();
    ~PopupMenu();
    void addColor(const QColor& color);

private:
    QButtonGroup *mButtonGroup;
    QGridLayout *mLayout;
    QHash<AbstractPopupMenuButton *, QColor> mColorToButton;

    void generateGrid();
    AbstractPopupMenuButton* createButton(const QColor& color);
    void addColorToGrid(const QColor &color);
    void clearGrid();
};

#endif //KCOLORPICKER_POPUPMENU_H
