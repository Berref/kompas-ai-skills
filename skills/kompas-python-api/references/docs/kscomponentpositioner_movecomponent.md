# MoveComponent - Переместить компонент

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс управления положением компонентов в сборке (Интерфейсы ksComponentPositioner, IComponentPositioner) ](kscomponentpositioner.html) > [IComponentPositioner - методы ](kscomponentpositioner_methods.html) |  Scroll [ [ [ ](kscomponentpositioner_prepare.html "К следующему разделу")](kscomponentpositioner_methods.html "На уровень выше")](kscomponentpositioner_finish.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscomponentpositioner.html)

Синтаксис Automation:

BOOL MoveComponent (double x, double y, double z);

Синтаксис COM:

BOOL MoveComponent (double x, double y, double z);

Входные параметры:

x, y, z | \- координаты точки сдвига.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Перед началом сдвига нужно задать плоскость и точку захвата. Сдвиг проводится в плоскости, которая определена относительно сборки. Начало перемещения определяется вызовом метода [Prepare](kscomponentpositioner_prepare.html) с типом pnMove. Окончание перемещения определяется вызовом метода [Finish](kscomponentpositioner_finish.html). Между ними может быть сколько угодно вызовов MoveComponent.

Подразделы:

(отсутствуют)
