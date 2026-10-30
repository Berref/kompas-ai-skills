# ksOpenMacro - Открыть макроэлемент для редактирования

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Составные объекты ](bt1730612.html) |  Scroll [ [ [ ](ksdocument2d_ksgetmacroparam.html "К следующему разделу")](bt1730612.html "На уровень выше")](ksdocument2d_ksmacro.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksOpenMacro](ksopenmacro.html).

Синтаксис Automation:

long ksOpenMacro (long macro);

Входной параметр:

macro | \- указатель на макроэлемент.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Когда макроэлемент открыт для редактирования; можно добавлять в его состав новые объекты вида, использовать метод [ksDocument2D::ksFindObj](ksdocument2d_ksfindobj.html).

Режим редактирования закрывается методом [ksDocument2D::ksEndObj](ksdocument2d_ksendobj.html);

В режиме редактирования открыт доступ к внутренним объектам макроэлементов. Теперь при создании макроэлемента или при добавлении к макроэлементу новых объектов вида выдается указатель на внутренние объекты, как и на самостоятельные объекты вида.

Допускается вводить пустой макроэлемент. Пустой макроэлемент является вырожденным объектом. Он существует только в период редактирования документа. После записи документа, в котором находился пустой макроэлемент, этот макроэлемент будет удален. Макроэлемент считается нормальным, если в нем находится хотя бы один внутренний объект.

Все методы работы с указателями на объекты допускают работу с внутренними объектами макроэлемента. Это методы:

[ksDocument2D::ksDeleteObj](ksdocument2d_ksdeleteobj.html)

[ksDocument2D::ksMoveObj](ksdocument2d_ksmoveobj.html)

[ksDocument2D::ksLightObj](ksdocument2d_kslightobj.html)

[ksDocument2D::ksTransformObj](ksdocument2d_kstransformobj.html)

[ksDocument2D::ksGetObjParam](ksdocument2d_ksgetobjparam.html)

[ksDocument2D::ksSetObjParam](ksdocument2d_kssetobjparam.html)

[ksDocument2D::ksRotateObj](ksdocument2d_ksrotateobj.html)

[ksDocument2D::ksCopyObj](ksdocument2d_kscopyobj.html)

[ksDocument2D::ksSymmetryObj](ksdocument2d_kssymmetryobj.html)

[ksDocument2D::ksEditViewObject](ksdocument2d_kseditviewobject.html)

[ksDocument2D::ksGetObjGabaritRect](ksdocument2d_ksgetobjgabaritrect.html)

[ksDocument2D::ksDecomposeObj](ksdocument2d_ksdecomposeobj.html)

Подразделы:

(отсутствуют)
