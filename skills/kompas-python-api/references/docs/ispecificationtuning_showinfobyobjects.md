# ShowInfoByObjects - Выдавать информацию по объектам (для исполнений более 10)

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationTuning ](ispecificationtuning.html) > [ISpecificationTuning - свойства ](ispecificationtuning_props.html) |  Scroll [ [ [ ](ispecificationtuning_showlistcountissameformat.html "К следующему разделу")](ispecificationtuning_props.html "На уровень выше")](ispecificationtuning_showembodimentwithoutvariables.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationtuning.html)

Тип данных: BOOL

Синтаксис Automation:

ShowInfoByObjects = iObject.ShowInfoByObjects | Получить свойство ([* ](1.html))  
---|---  
iObject.ShowInfoByObjects = ShowInfoByObjects | Установить свойство ([* ](1.html))  
ShowInfoByObjects = iObject.GetShowInfoByObjects() | Получить свойство ([**](2.html))  
iObject.SetShowInfoByObjects (ShowInfoByObjects) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ShowInfoByObjects (&ShowInfoByObjects ) | Получить свойство  
---|---  
iObject->put_ShowInfoByObjects (ShowInfoByObjects) | Установить свойство  
  
Значения свойства:

TRUE | \- выдавать информацию по объектам,  
---|---  
FALSE | \- выдавать информацию блоками.  
  
Примечание:

Позволяет выбрать способ отображения информации.

Свойство имеет смысл, если число исполнений, введенное в общих настройках спецификации, больше, чем количество колонок бланка спецификации, предназначенное для ввода количества на исполнение, становятся доступны выбора способа отображения информации.

Подразделы:

(отсутствуют)
