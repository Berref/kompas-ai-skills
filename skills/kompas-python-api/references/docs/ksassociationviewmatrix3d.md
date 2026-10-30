# ksAssociationViewMatrix3D - Создать матрицу ассоциативного вида

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с видами ](cm1826821.html) > [Функции работы с видами ](views_fncts_common.html) |  Scroll [ [ [ ](kscreatesheetarbitraryview.html "К следующему разделу")](views_fncts_common.html "На уровень выше")](getviewreference.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksAssociationViewMatrix3D](ksdocument2d_ksassociationviewmatrix3d.html).

Синтаксис:

VARIANT ksAssociationViewMatrix3D (reference view);

Входные параметры:

view | \- указатель на ассоциативный вид.  
---|---  
  
Возвращаемое значение:

SAFEARRAY double (VT_ARRAY | VT_R8) В массиве будут лежать 16 элементов, которые представляют собой матрицу размера 4х4.  
---  
  
Примечание:

Если указатель на вид не задан (view = 0), то функция будет выполняться для текущего вида.

Подразделы:

(отсутствуют)
