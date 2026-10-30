# Variable - Получить параметрическую переменную по имени, индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IFeature7 ](ifeature7.html) > [IFeature7 - свойства ](ifeature7_props.html) |  Scroll [ [ [ ](ifeature7_variables.html "К следующему разделу")](ifeature7_props.html "На уровень выше")](ifeature7_valid.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifeature7.html)

Тип данных: указатель на интерфейс [IVariable7](ivariable7.html)

Синтаксис Automation:

Variable = Object.Variables( External, InSource, Index ) | Получить свойство ([* ](1.html))  
---|---  
Variable = Object.GetVariables( External, InSource, Index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Variable = Object.GetVariables( External, InSource, Index ) | Получить свойство  
---|---  
  
Входные параметры:

BOOL ExternalOnly | \- только внешние,  
---|---  
BOOL InSource | \- из источника,  
VARIANT Index | \- имя или индекс переменной.  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
