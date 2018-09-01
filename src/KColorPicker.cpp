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

#include <kColorPicker/KColorPicker.h>

#include "IconCreator.h"
#include "PopupMenu.h"

class KColorPicker::Impl : public QSharedData
{
public:
    explicit Impl();
    ~Impl();
    QIcon createIcon(const QColor & color);
    QMenu* popupMenu();
    void addColor(const QColor &color);

private:
    IconCreator *mIconCreator;
    PopupMenu *mPopupMenu;
};

KColorPicker::KColorPicker() : mImpl(new Impl())
{
    addDefaultColors();
    setPopupMode(QToolButton::InstantPopup);
    setMenu(mImpl->popupMenu());
    for (auto color : mColors) {
        mImpl->addColor(color);
    }
}

KColorPicker::~KColorPicker()
{
}

void KColorPicker::selectColor(const QColor &color)
{
    if(!mColors.contains(color)) {
        mColors.append(color);
    }
    auto icon = mImpl->createIcon(color);
    setIcon(icon);

}

void KColorPicker::addDefaultColors()
{
    mColors.append(QColor(Qt::red));
    mColors.append(QColor(Qt::green));
    mColors.append(QColor(Qt::blue));
    mColors.append(QColor(Qt::yellow));
    mColors.append(QColor(Qt::magenta));
    mColors.append(QColor(Qt::cyan));
    mColors.append(QColor(Qt::white));
    mColors.append(QColor(Qt::black));
}

//
// Impl
//
KColorPicker::Impl::Impl()
{
    mIconCreator = new IconCreator();
    mPopupMenu = nullptr;
}

KColorPicker::Impl::~Impl()
{
    delete mIconCreator;
}

QIcon KColorPicker::Impl::createIcon(const QColor &color)
{
    return mIconCreator->createIcon(color);
}

QMenu *KColorPicker::Impl::popupMenu()
{
    mPopupMenu = new PopupMenu();
    return dynamic_cast<QMenu*>(mPopupMenu);
}

void KColorPicker::Impl::addColor(const QColor &color)
{
    mPopupMenu->addColor(color);
}
