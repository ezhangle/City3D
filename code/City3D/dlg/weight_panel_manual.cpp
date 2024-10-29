/*
Copyright (C) 2017  Liangliang Nan
https://3d.bk.tudelft.nl/liangliang/ - liangliang.nan@gmail.com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "weight_panel_manual.h"
#include "main_window.h"
#include "paint_canvas.h"
#include "../method/method_global.h"


WeightPanelManual::WeightPanelManual(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	mainWindow_ = dynamic_cast<MainWindow*>(parent);
	updateUI();
}


void WeightPanelManual::updateUI() {
	float fitting = truncate_digits(Method::lambda_data_fitting, 3);
	float coverage = truncate_digits(Method::lambda_model_height, 3);
	float complexity = truncate_digits(Method::lambda_model_complexity, 3);
    float min_points=Method::min_points;
    float pixel_size=Method::pixel_size;

	QString text_fitting = QString("%1").arg(fitting);
	QString text_coverage = QString("%1").arg(coverage);
	QString text_complexity = QString("%1").arg(complexity);
    QString text_min_points = QString("%1").arg(min_points);
    QString text_pixel_size = QString("%1").arg(pixel_size);

	lineEditFitting->setText(text_fitting);
	lineEditHeight->setText(text_coverage);
	lineEditComplexity->setText(text_complexity);
    lineEditMinPoints->setText(text_min_points);
    lineEditPixelSize->setText(text_pixel_size);
}


void WeightPanelManual::updateWeights() {
	Method::lambda_data_fitting = lineEditFitting->text().toFloat();
	Method::lambda_model_height = lineEditHeight->text().toFloat();
	Method::lambda_model_complexity = lineEditComplexity->text().toFloat();
    Method::min_points=lineEditMinPoints->text().toFloat();
    Method::pixel_size=lineEditPixelSize->text().toFloat();
}