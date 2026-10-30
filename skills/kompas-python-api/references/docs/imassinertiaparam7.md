# Интерфейс IMassInertiaParam7

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) |  Scroll [ [ [ ](imassinertiaparam7_props.html "К следующему разделу")](bc2609111.html "На уровень выше")](ifeature7_delete.html "К предыдущему разделу")  
---|---  
  
Интерфейс массово-центровочных характеристик.

Иерархия:

IDispatch

[IMassInertiaParam7](imassinertiaparam7.html)

Примечание:

1\. Интерфейс контейнера является дополнительным к интерфейсу [IPart7](ipart7.html) и [IEmbodiment](iembodiment.html). Данный интерфейс можно получить от IPart7 и от IEmbodiment посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html);

2\. Интерфейс позволяет получить доступ к массово-центровочным характеристикам детали и сборки. С помощью интерфейса можно получить и отредактировать массово-центровочные характеристики объекта.

3\. Новые характеристики вступают в силу после вызова метода [ImodelObject::Update](imodelobject_update.html).

Подразделы:

[IMassInertiaParam7 - свойства ](imassinertiaparam7_props.html)

[IMassInertiaParam7 - методы ](imassinertiaparam7_methods.html)
