# Variables - Получить массив параметрических переменных в виде SAFEARRAY VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IFeature7 ](ifeature7.html) > [IFeature7 - свойства ](ifeature7_props.html) |  Scroll [ [ [ ](ifeature7_variablescount.html "К следующему разделу")](ifeature7_props.html "На уровень выше")](ifeature7_variable.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifeature7.html)

Тип данных: VARIANT

Синтаксис Automation:

Variables = Object.Variables( ExternalOnly, InSource ) | Получить свойство ([* ](1.html))  
---|---  
Variables = Object.GetVariables( ExternalOnly, InSource ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Variables( ExternalOnly, InSource, &Variables ) | Получить свойство  
---|---  
  
Входные параметры:

BOOL ExternalOnly | \- только внешние,  
---|---  
BOOL InSource | \- из источника.  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
