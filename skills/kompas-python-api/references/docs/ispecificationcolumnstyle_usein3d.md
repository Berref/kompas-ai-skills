# UseIn3D - Используется в модели

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationColumnStyle ](ispecificationcolumnstyle.html) > [ISpecificationColumnStyle - свойства ](ispecificationcolumnstyle_props.html) |  Scroll [ [ [ ](ispecificationcolumnstyle_valuetype.html "К следующему разделу")](ispecificationcolumnstyle_props.html "На уровень выше")](ispecificationcolumnstyle_useforsectiontitle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcolumnstyle.html)

Тип данных: BOOL

Синтаксис Automation:

UseIn3D = iObject.UseIn3D | Получить свойство ([* ](1.html))  
---|---  
UseIn3D = iObject.GetUseIn3D() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_UseIn3D (&UseIn3D) | Получить свойство  
---|---  
  
Значения свойства:

TRUE | \- в колонку можно было вводить данные при формировании объектов спецификации в документе-модели,  
---|---  
FALSE | \- заполнение колонки в объектах спецификации модели невозможно.  
  
Примечание:

1\. Свойство позволяет настроить стиль спецификации так, чтобы в документах-моделях формировались частично заполненные объекты спецификации. Это позволяет избежать конфликтов взаимодействия документа-модели со спецификацией и чертежом.

2\. Используется только для колонок, полученных у стиля спецификации [ISpecificationStyle](ispecificationstyle.html).

3\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
