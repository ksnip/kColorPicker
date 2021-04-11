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

#ifndef KCOLORPICKER_POPUPMENU_H
#define KCOLORPICKER_POPUPMENU_H

#include <QMenu>
#include <QGridLayout>
#include <QButtonGroup>

#include "IconCreator.h"
#include "buttons/ColorButton.h"
#include "buttons/ColorDialogButton.h"

namespace kColorPicker {

class PopupMenu : public QMenu
{
Q_OBJECT
public:
	PopupMenu();
	~PopupMenu() override;
	void addColor(const QColor &color);
	void selectColor(const QColor &color);
	QSize sizeHint() const;

signals:
	void colorChanged(const QColor &color) const;

private:
	QButtonGroup *mButtonGroup;
	QGridLayout *mLayout;
	QList<ColorButton *> mColorButtons;
	ColorDialogButton *mColorDialogButton;

	void generateGrid();
	static ColorButton *createButton(const QColor &color);
	void addColorButton(const QColor &color);
	void clearGrid();
	bool isColorInGrid(const QColor &color);

private slots:
	void colorSelected(const QColor &color);
};

} // namespace kColorPicker
#endif //KCOLORPICKER_POPUPMENU_H
