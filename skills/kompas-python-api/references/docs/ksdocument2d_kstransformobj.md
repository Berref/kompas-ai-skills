# ksTransformObj - Преобразовать объект по установленной матрице

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Операции редактирования ](bt1734633.html) |  Scroll [ [ [ ](ksdocument2d_kstrimnurbs.html "К следующему разделу")](bt1734633.html "На уровень выше")](ksdocument2d_kssymmetryobj.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [TransformObj](transformobj.html).

Синтаксис Automation:

long ksTransformObj (long ref);

Входной параметр:

ref | \- указатель на объект.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Для работы с матрицами служат методы [ksDocument2D::ksMtr](ksdocument2d_ksmtr.html) и [ksDocument2D::ksDeleteMtr](ksdocument2d_ksdeletemtr.html).

Подразделы:

(отсутствуют)
