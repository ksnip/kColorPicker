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

#ifndef KCOLORPICKER_KCOLORPICKER_H
#define KCOLORPICKER_KCOLORPICKER_H

#include <QToolButton>
#include <QColor>
#include <QList>

#include <kColorPicker/KColorPickerExport.h>

namespace kColorPicker {

class KColorPickerPrivate;

class KCOLORPICKER_EXPORT KColorPicker : public QToolButton
{
Q_OBJECT

	Q_DECLARE_PRIVATE(KColorPicker)

public:
	explicit KColorPicker();
	~KColorPicker() override;
	void setFixedSize(const QSize &size);
	void setFixedSize(int width, int height);
	QColor color() const;

public Q_SLOTS:
	void setColor(const QColor &color);

Q_SIGNALS:
	void colorChanged(const QColor &color) const;

private:
	QScopedPointer<KColorPickerPrivate> const d_ptr;

private Q_SLOTS:
	void setColorIcon(const QColor &color);
	void setIconSize(const QSize &size);
	void colorSelected(const QColor &color);
};

}

#endif //KCOLORPICKER_KCOLORPICKER_H
