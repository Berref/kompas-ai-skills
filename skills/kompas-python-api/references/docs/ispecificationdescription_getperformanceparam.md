# GetPerformanceParam - Получить параметры и имя колонки исполнения по индексу

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationDescription ](ispecificationdescription.html) > [ISpecificationDescription - методы ](ispecificationdescription_methods.html) |  Scroll [ [ [ ](ispecificationdescription_getspecificationobjectsforgeom.html "К следующему разделу")](ispecificationdescription_methods.html "На уровень выше")](ispecificationdescription_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationdescription.html)

Синтаксис Automation:

LPCTSTR GetPerformanceParam( long DisplayPerformanceIndex, long * PerformanceIndex, long * BlockIndex );

Синтаксис COM:

HRESULT GetPerformanceParam( long DisplayPerformanceIndex, long * PerformanceIndex, long * BlockIndex, BSTR * PerformanceName );

Входные параметры:

DisplayPerformanceIndex | \- индекс отображаемого исполнения (начинается с единицы).  
---|---  
  
Выходные параметры:

PerformanceIndex | \- номер колонки исполнения,  
---|---  
BlockIndex | \- указатель на структуру параметров библиотечной панели свойств.  
  
Возвращаемое значение:

| \- Имя исполнения.  
---|---  
  
Метод позволяет получить имя исполнения, номер исполнения и номер блока по индексу исполнения.

Примечание:

1\. Индекс исполнения начинается с единицы.

2\. В групповой спецификации по варианту Б, созданной по сборке, у которой есть исполнения с непоследовательными номерами исполнений, часть колонок исполнений может быть отключена и отображаться будут только те исполнения, которые пришли из сборки. В такой спецификации в одной строке объекта спецификации могут отображаться исполнения и количество из нескольких блоков.

3\. В групповой спецификации по варианту A также могут быть непоследовательные номера исполнений, если спецификация создана по сборке.

4\. Метод рекомендуется использовать вместо свойства [ISpecificationDescription::PerformanceName](ispecificationdescription_performancename.html).PerformanceIndex и BlockIndex позволяют сопоставить имя исполнения и значение количества в конкретной колонке количество объектов спецификации.

Подразделы:

(отсутствуют)
