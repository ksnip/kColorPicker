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
    QIcon createIconWithSize(const QColor & color, const QSize &size);
    PopupMenu* popupMenu();
    void addColor(const QColor &color);
    void selectColor(const QColor &color);
    QColor selectedColor() const;

private:
    PopupMenu *mPopupMenu;
    QColor mSelectedColor;
};

KColorPicker::KColorPicker() : mImpl(new Impl())
{
    setPopupMode(QToolButton::InstantPopup);
    auto popupMenu = mImpl->popupMenu();
    setMenu(popupMenu);
    connect(popupMenu, &PopupMenu::colorChanged, this, &KColorPicker::colorSelected);
    addDefaultColors();
    setColor(QColor(Qt::red));
}

KColorPicker::~KColorPicker()
{
}

void KColorPicker::setColor(const QColor &color)
{
    setColorIcon(color);
    mImpl->selectColor(color);
}

void KColorPicker::addDefaultColors()
{
    mImpl->addColor(QColor(Qt::red));
    mImpl->addColor(QColor(Qt::green));
    mImpl->addColor(QColor(Qt::blue));
    mImpl->addColor(QColor(Qt::yellow));
    mImpl->addColor(QColor(Qt::magenta));
    mImpl->addColor(QColor(Qt::cyan));
    mImpl->addColor(QColor(Qt::white));
    mImpl->addColor(QColor(Qt::black));
}

void KColorPicker::setColorIcon(const QColor &color)
{
    auto icon = mImpl->createIcon(color);
    setIcon(icon);
}

void KColorPicker::setColorIconWithSize(const QColor &color, const QSize &size)
{
    auto scaleFactor = 0.6;
    auto scaledSize = size * scaleFactor;
    auto icon = mImpl->createIconWithSize(color, scaledSize);
    setIconSize(scaledSize);
    setIcon(icon);
}

void KColorPicker::colorSelected(const QColor &color)
{
    setColorIcon(color);
    emit colorChanged(color);
}

void KColorPicker::setFixedSize(const QSize &size)
{
    QToolButton::setFixedSize(size);
    setColorIconWithSize(mImpl->selectedColor(), size);
}

void KColorPicker::setFixedSize(int width, int height)
{
    QToolButton::setFixedSize(width, height);
    setColorIconWithSize(mImpl->selectedColor(), QSize(width, height));
}

//
// Impl
//
KColorPicker::Impl::Impl()
{
    mPopupMenu = new PopupMenu();;
}

KColorPicker::Impl::~Impl()
{
    delete mPopupMenu;
}

QIcon KColorPicker::Impl::createIcon(const QColor &color)
{
    return IconCreator::createIcon(color);
}

QIcon KColorPicker::Impl::createIconWithSize(const QColor &color, const QSize &size)
{
    return IconCreator::createIcon(color, size);
}

PopupMenu *KColorPicker::Impl::popupMenu()
{
    return mPopupMenu;
}

void KColorPicker::Impl::addColor(const QColor &color)
{
    mPopupMenu->addColor(color);
    mSelectedColor = color;
}

void KColorPicker::Impl::selectColor(const QColor &color)
{
    mPopupMenu->selectColor(color);
}

QColor KColorPicker::Impl::selectedColor() const
{
    return mSelectedColor;
}
