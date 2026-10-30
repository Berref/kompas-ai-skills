# Пример изменения порядка NURBS

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
Изменить порядок NURBS кривой на 4.

nurbs.Degree = 4 нужно устанавливать не раньше, чем в NURBS кривую добавятся 4 точки.

nurbs = nurbses.Add()

nurbs.Style = kompas6_constants.ksCSNormal

nurbs.Closed = False

#nurbs.Degree = 4

nurbs.AddPoint(0, 49.7220581829, 124.864112265, 1.0)

nurbs.AddPoint(1, 79.97915965, 161.394027451, 1.0)

nurbs.AddPoint(2, 110.974239202, 124.864112265, 1.0)

nurbs.AddPoint(3, 173.702376389, 181.688424777, 1.0)

nurbs.Degree = 4

nurbs.Update()
