# Prepare - Подготовиться к перемещению компонента

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IComponentPositioner7](icomponentpositioner7.html) > [IComponentPositioner7 - методы](icomponentpositioner7_methods.html) |  Scroll [ [ [ ](icomponentpositioner7_rotatecomponent.html "К следующему разделу")](icomponentpositioner7_methods.html "На уровень выше")](icomponentpositioner7_movecomponent.html "К предыдущему разделу")  
---|---  
  
[Интерфейс](icomponentpositioner7.html)

Синтаксис Automation:

long Prepare( IPart7 * Part, Positioner_Type PositionerType );

Синтаксис COM:

HRESULT Prepare( IPart7 * Part, Positioner_Type PositionerType, long * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Part | \- указатель на интерфейс компонента [IPart7](ipart7.html),  
---|---  
PositionerType | \- тип перемещения из перечисления [Positioner_Type](positioner_type.html).  
  
Подразделы:

(отсутствуют)
