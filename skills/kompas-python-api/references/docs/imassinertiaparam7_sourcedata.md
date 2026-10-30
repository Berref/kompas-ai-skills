# SourceData - Данные из источника

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IMassInertiaParam7 ](imassinertiaparam7.html) > [IMassInertiaParam7 - свойства ](imassinertiaparam7_props.html) |  Scroll [ [ [ ](imassinertiaparam7_volume.html "К следующему разделу")](imassinertiaparam7_props.html "На уровень выше")](imassinertiaparam7_materiallocation.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imassinertiaparam7.html)

Тип данных: BOOL

Синтаксис Automation:

SourceData = iObject.SourceData | Получить свойство ([* ](1.html))  
---|---  
iObject.SourceData = SourceData | Установить свойство ([* ](1.html))  
SourceData = iObject.GetSourceData( ) | Получить свойство ([**](2.html))  
iObject.SetDensityMode( DensityMode ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_SourceData( &SourceData ) | Получить свойство  
---|---  
iObject->put_SourceData( SourceData ) | Установить свойство  
  
Значения свойства:

TRUE | \- данные из источника,  
---|---  
FALSE | \- отличаются от источника.  
  
Примечание:

1\. Свойство доступно только для компонента, вставленного в сборку.

2\. Свойство позволяет установить и получить признак того, что данные взяты из источника.

Подразделы:

(отсутствуют)
