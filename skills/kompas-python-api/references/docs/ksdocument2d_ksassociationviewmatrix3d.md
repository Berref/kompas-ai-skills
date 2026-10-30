# ksAssociationViewMatrix3D - Создать матрицу ассоциативного вида

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_kscalcrasterscale.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_getstampex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksAssociationViewMatrix3D](ksassociationviewmatrix3d.html).

Синтаксис Automation:

VARIANT ksAssociationViewMatrix3D (long view);

Входные параметры:

view | \- указатель на ассоциативный вид.  
---|---  
  
Возвращаемое значение:

SAFEARRAY double (VT_ARRAY | VT_R8) В массиве будут лежать 16 элементов, которые представляют собой матрицу размера 4х4.  
---  
  
Примечание:

Если указатель на вид не задан (view = 0), то метод будет выполняться для текущего вида.

Подразделы:

(отсутствуют)
