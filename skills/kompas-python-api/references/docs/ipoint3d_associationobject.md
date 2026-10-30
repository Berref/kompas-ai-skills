# AssociationObject - Опорный объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [IPoint3D - свойства ](ipoint3d_props.html) |  Scroll [ [ [ ](ipoint3d_parameters.html "К следующему разделу")](ipoint3d_props.html "На уровень выше")](ipoint3d_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipoint3d.html)

Тип данных: указатель на интерфейс объекта [IModelObject](imodelobject.html)

Синтаксис Automation:

AssociationObject = iObject.AssociationObject; | Получить свойство ([* ](1.html))  
---|---  
AssociationObject = iObject.GetAssociationObject(); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_AssociationObject( &AssociationObject ); | Получить свойство  
---|---  
  
Примечание.

1\. Установить значение свойства можно только при типе параметров "по координатам" [IPoint3D::ParameterType](ipoint3d_parametertype.html).

2\. Для установки объекта необходимо вызвать функцию [IPoint3D::SetAssociationObject](ipoint3d_setassociationobject.html).

Подразделы:

(отсутствуют)
