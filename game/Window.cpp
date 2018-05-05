#include <QPainter>
#include <QtMath>

#include "Window.h"

Window::Window()
	: m_playerTurnHandler(m_playerHandler)
	, m_keyInputHandler(m_playerTurnHandler)
{
}

void Window::keyReleaseEvent(QKeyEvent *event)
{
	m_keyInputHandler.onKeyPress(event->key());
}

QPainterPath createPath(const QPointF &start, double angle, double length, double thickness)
{
	const double radians1 = qDegreesToRadians(-angle - 180.0);
	const double radians2 = qDegreesToRadians(-angle - 90.0);
	const double radians3 = qDegreesToRadians(-angle);

	const double sx1 = thickness * cos(radians1) + start.x();
	const double sy1 = thickness * sin(radians1) + start.y();

	const double cx1 = (thickness / 2.0) * cos(radians2) + sx1;
	const double cy1 = (thickness / 2.0) * sin(radians2) + sy1;

	const double ex1 = thickness * cos(radians2) + start.x();
	const double ey1 = thickness * sin(radians2) + start.y();

	const double cx2 = (thickness / 2.0) * cos(radians1) + ex1;
	const double cy2 = (thickness / 2.0) * sin(radians1) + ey1;

	const double ex2 = thickness * cos(radians3) + start.x();
	const double ey2 = thickness * sin(radians3) + start.y();

	const double cx3 = (thickness / 2.0) * cos(radians3) + ex1;
	const double cy3 = (thickness / 2.0) * sin(radians3) + ey1;

	const double cx4 = (thickness / 2.0) * cos(radians2) + ex2;
	const double cy4 = (thickness / 2.0) * sin(radians2) + ey2;

	QPainterPath path;
	path.moveTo(sx1, sy1);
	path.cubicTo(cx1, cy1, cx2, cy2, ex1, ey1);
	path.cubicTo(cx3, cy3, cx4, cy4, ex2, ey2);
//	path.addEllipse(start, 0.1, 0.1);
//	path.addEllipse(sx1, sy1, 0.1, 0.1);
//	path.addEllipse(ex1, ey1, 0.1, 0.1);
//	path.addEllipse(cx1, cy1, 0.1, 0.1);
//	path.addEllipse(cx2, cy2, 0.1, 0.1);
//	path.moveTo(noseBase.left(), noseBase.center().y());
//	path.arcTo(noseBase, 220, -180);
//	path.lineTo(3 * cos(angle3) + 20.5 + 0.75 * cos(angle1), 3 * sin(angle3) + 13 + 0.75 * sin(angle1));
//	path.lineTo(3 * cos(angle3) + 20.5 + 0.75 * cos(angle2), 3 * sin(angle3) + 13 + 0.75 * sin(angle2));

	return path;
}

void Window::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);

	QTransform transform;
	transform.scale(20, 20);
//	transform.shear(0, -0.572958);
	transform.translate(0, 2);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setTransform(transform);

	QPolygon leftFace;
	leftFace << QPoint(10, 0);
	leftFace << QPoint(10, 8);
	leftFace << QPoint(17, 16);
	leftFace << QPoint(17, 8);

	QPolygon topFace;
	topFace << QPoint(10, 0);
	topFace << QPoint(17, 8);
	topFace << QPoint(24, 8);
	topFace << QPoint(17, 0);

	QPolygon frontFace;
	frontFace << QPoint(17, 8);
	frontFace << QPoint(17, 16);
	frontFace << QPoint(24, 16);
	frontFace << QPoint(24, 8);

	QRectF noseBase(19.75, 12.25, 1.5, 1.5);
	QRectF noseSomething(22, 15, 2, 2);
	QRectF noseTip(25.5, 19, 2, 2);

	const double angle1 = qDegreesToRadians(-40.0);
	const double angle2 = qDegreesToRadians(-220.0);
	const double angle3 = qDegreesToRadians(50.0);

	QPainterPath path = createPath(QPointF(20.5, 12.5), 40, 3, 2);
//	path.moveTo(noseBase.left(), noseBase.center().y());
//	path.arcTo(noseBase, 220, -180);
//	path.lineTo(3 * cos(angle3) + 20.5 + 0.75 * cos(angle1), 3 * sin(angle3) + 13 + 0.75 * sin(angle1));
//	path.lineTo(3 * cos(angle3) + 20.5 + 0.75 * cos(angle2), 3 * sin(angle3) + 13 + 0.75 * sin(angle2));

	QPolygonF nose1;
	nose1 << QPointF(0.75 * cos(angle1) + 20.5, 0.75 * sin(angle1) + 13);
	nose1 << QPointF(3 * cos(angle3) + 20.5 + 0.75 * cos(angle1), 3 * sin(angle3) + 13 + 0.75 * sin(angle1));
	nose1 << QPointF(3 * cos(angle3) + 20.5 + 0.75 * cos(angle2), 3 * sin(angle3) + 13 + 0.75 * sin(angle2));
	nose1 << QPointF(0.75 * cos(angle2) + 20.5, 0.75 * sin(angle2) + 13);

//	QPolygonF nose2;
//	nose2 << QPointF(cos(angle1) + 23, sin(angle1) + 16);
//	nose2 << QPointF(cos(angle1) + 26.5, sin(angle1) + 20);
//	nose2 << QPointF(cos(angle2) + 26.5, sin(angle2) + 20);
//	nose2 << QPointF(cos(angle2) + 23, sin(angle2) + 16);

	painter.setPen(Qt::NoPen);

	painter.setBrush(QBrush("#6f918a"));
	painter.drawPolygon(leftFace);

	painter.setBrush(QBrush("#dbe3e2"));
	painter.drawPolygon(topFace);

	painter.setBrush(QBrush("#93aca7"));
	painter.drawPolygon(frontFace);

	painter.setBrush(QBrush("#374845"));
	painter.drawRect(QRectF(18, 9, 1.5, 1));
	painter.drawRect(QRectF(21.5, 9, 1.5, 1));

	painter.setBrush(QBrush("white"));
	painter.drawRect(QRectF(18, 10, 1.5, 3));
	painter.drawRect(QRectF(21.5, 10, 1.5, 3));

	painter.setBrush(QBrush("#87cdde"));
	painter.drawRect(QRectF(18.5, 11, 1, 2));
	painter.drawRect(QRectF(21.5, 11, 1, 2));

	painter.setBrush(QBrush("#ffaaee"));
	painter.drawRect(QRectF(18, 13, 1, 1));
	painter.drawRect(QRectF(22, 13, 1, 1));

	painter.setBrush(QBrush("#ff5555"));
	painter.drawRect(QRectF(19.5, 14, 2, 1));

	painter.setBrush(QBrush("red"));
	painter.drawEllipse(noseBase);
	painter.setBrush(QBrush("#b7c8c4"));
	painter.drawPolygon(nose1);

	painter.setBrush(QBrush("green"));
	painter.drawPath(path);

//	painter.setBrush(QBrush("#dbe3e2"));
//	painter.drawEllipse(noseSomething);
//	painter.drawPolygon(nose2);

//	painter.setBrush(QBrush("#b7c8c4"));
//	painter.drawEllipse(noseTip);

//	painter.setBrush(QBrush("#374845"));
//	painter.drawEllipse(noseTip.adjusted(0.4, 0.4, -0.4, -0.4));

	update();
}
