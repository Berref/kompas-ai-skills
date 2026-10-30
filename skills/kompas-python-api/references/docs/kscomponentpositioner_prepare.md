# Prepare - Подготовиться к перемещению компонента

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс управления положением компонентов в сборке (Интерфейсы ksComponentPositioner, IComponentPositioner) ](kscomponentpositioner.html) > [IComponentPositioner - методы ](kscomponentpositioner_methods.html) |  Scroll [ [ [ ](kscomponentpositioner_rotatecomponent.html "К следующему разделу")](kscomponentpositioner_methods.html "На уровень выше")](kscomponentpositioner_movecomponent.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscomponentpositioner.html)

Синтаксис Automation:

long Prepare(ksPart * part, Positioner_Type positionerType);

Синтаксис COM:

long Prepare(LPPART part, Positioner_Type positionerType);

Входные параметры:

part | \- указатель на интерфейс компоненты [ksPart](kspart.html) или [IPart](kspart.html),  
---|---  
positionerType | \- [тип перемещения](positioner_type.html).  
  
Возвращаемое значение:

0 | \- в случае успешного завершения,  
---|---  
1 | \- в случае неудачи.  
  
Примечание:

Окончание перемещения определяется вызовом метода [Finish](kscomponentpositioner_finish.html). Между ними может быть сколько угодно вызовов [MoveComponent](kscomponentpositioner_movecomponent.html) или [RotateComponent](kscomponentpositioner_rotatecomponent.html) в зависимости от указанного [типа перемещения](positioner_type.html).

Подразделы:

(отсутствуют)
