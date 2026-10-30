# ksOpenMacro - Открыть макроэлемент для редактирования

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Работа с макроэлементами и библиотечными макроэлементами ](cm1919792.html) > [Функции работы с макроэлементами и библиотечными макроэлементами ](lib_macro_object_def.html) |  Scroll [ [ [ ](kssetmacroparam.html "К следующему разделу")](lib_macro_object_def.html "На уровень выше")](ksgetmacrowaitdblclickedit.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksopenmacro_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksOpenMacro](ksdocument2d_ksopenmacro.html).

Синтаксис:

int ksOpenMacro(reference macro);

Входной параметр:

macro | \- указатель на макроэлемент.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. После вызова функции можно добавлять в macro новые объекты вида, использовать функцию FindObj; режим закрывается функцией EndObj();

2\. Открыт доступ к внутренним объектам макроэлементов. Теперь при создании макроэлемента или при добавлении к макроэлементу новых объектов вида, на внутренние объекты выдается указатель (reference), как и на самостоятельные объекты вида.

[Пример...](ksopenmacro_example1.html).

3\. Допускается вводить пустой макроэлемент. Пустой макроэлемент является вырожденным объектом. Он живет только в период редактирования документа. После записи документа, в котором находился пустой макро, этот макро будет удален. Макроэлемент считается нормальным, если в нем находится хотя бы один внутренний объект.

[Пример…](ksopenmacro_example2.html)

4\. Функции работы с указателями на объекты допускают работу с внутренними объектами

макроэлемента. К ним относятся:

– [CopyObj](copyobj.html)

– [DecomposeObj](decomposeobj.html)

– [DeleteObj](deleteobj.html)

– [GetObjGabaritRect](getobjgabaritrect.html)

– [GetObjParam](getobjparam.html)

– [ksEditViewObject](kseditviewobject.html)

– [LightObj](lightobj.html)

– [MoveObj](moveobj.html)

– [RotateObj](rotateobj.html)

– [SetObjParam](setobjparam.html)

– [SymmetryObj](symmetryobj.html)

– [TransformObj](transformobj.html)

Подразделы:

(отсутствуют)
