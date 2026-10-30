# NeedRebuild - Необходимость перестроения спецификации

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationDescription ](ispecificationdescription.html) > [ISpecificationDescription - свойства ](ispecificationdescription_props.html) |  Scroll [ [ [ ](ispecificationdescription_objects.html "К следующему разделу")](ispecificationdescription_props.html "На уровень выше")](ispecificationdescription_layoutname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationdescription.html)

Тип данных: BOOL

Синтаксис Automation:

NeedRebuild = Object.NeedRebuild | Получить свойство ([* ](1.html))  
---|---  
Object.NeedRebuild = NeedRebuild | Установить свойство ([* ](1.html))  
NeedRebuild = Object.GetNeedRebuild() | Получить свойство ([**](2.html))  
Object.SetNeedRebuild (NeedRebuild) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_NeedRebuild( &NeedRebuild ) | Получить свойство  
---|---  
Object.put_NeedRebuild( NeedRebuild ) | Установить свойство  
  
Примечание:

1\. Свойство позволяет временно отключить обновление окна документа спецификации из функций API при создании и изменении объектов спецификации. А также ускорить:

•создание и изменение большого количества объектов,

•работу функции изменения имен исполнений в групповых спецификациях.

2\. При изменении объектов спецификации можно воспользоваться свойством [ISpecificationDescription::PerformanceName](ispecificationdescription_performancename.html) или методом [ISpecificationObject::Update](ispecificationobject_update.html).

Подразделы:

(отсутствуют)
