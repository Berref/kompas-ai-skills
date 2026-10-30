# PerformanceName - Отображаемое имя исполнения

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationDescription ](ispecificationdescription.html) > [ISpecificationDescription - свойства ](ispecificationdescription_props.html) |  Scroll [ [ [ ](ispecificationdescription_showallobjects.html "К следующему разделу")](ispecificationdescription_props.html "На уровень выше")](ispecificationdescription_performancecountinblock.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationdescription.html)

Тип данных: BSTR

Синтаксис Automation:

PerformanceName = iObject.PerformanceName( PerformanceIndex, BlockIndex ) | Получить свойство ([* ](1.html))  
---|---  
iObject.PerformanceName( PerformanceIndex, BlockIndex ) = PerformanceName | Установить свойство ([* ](1.html))  
PerformanceName = iObject.GetPerformanceName( PerformanceIndex, BlockIndex ) | Получить свойство ([**](2.html))  
iObject.SetPerformanceName( PerformanceIndex, BlockIndex, PerformanceName ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject.get_PerformanceName( PerformanceIndex, BlockIndex, &PerformanceName ) | Получить свойство  
---|---  
iObject.put_PerformanceName( PerformanceIndex, BlockIndex, PerformanceName ) | Установить свойство  
  
Входные параметры:

PerformanceIndex | \- номер колонки типа "количество", начиная с 1(актуально для СП по варианту Б),  
---|---  
BlockIndex | \- номер блока, начиная с 0 (актуально для СП по варианту A).  
  
Примечание:

1\. В текст обозначения исполнения, которое редактируется, нужно включать разделитель.

2\. Для получения имен исполнений рекомендуется использовать метод [ISpecificationDescription::GetPerformanceParam.](ispecificationdescription_getperformanceparam.html)

3\. Для ускорения работы функции при массовом изменении спецификации рекомендуется воспользоваться методом [ISpecificationDescription::NeedRebuild](ispecificationdescription_needrebuild.html).

Подразделы:

(отсутствуют)
