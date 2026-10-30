# AddStep - Добавить шаг

[API интерфейсов. Версия 7](applicate.html) > [Сервисные функции ](service.html) > [Динамическое сечение ](cu1734180.html) > [Интерфейс IDynamicCrossSection ](idynamiccrosssection.html) > [IDynamicCrossSection - методы ](idynamiccrosssection_methods.html) |  Scroll [ [ [ ](idynamiccrosssection_delete.html "К следующему разделу")](idynamiccrosssection_methods.html "На уровень выше")](idynamiccrosssection_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idynamiccrosssection.html)

Синтаксис Automation:

LPDISPATCH AddStep( ksDynamicCrossSectionStepBuildingTypeEnum BuildingType );

Синтаксис COM:

HRESULT AddStep( ksDynamicCrossSectionStepBuildingTypeEnum BuildingType, IDynamicCrossSectionStep * * Result );

Возвращаемое значение:

| Указатель на интерфейс [IDynamicCrossSectionStep](idynamiccrosssectionstep.html).  
---|---  
  
Входные параметры:

BuildingType IPropert | \- Способ создания шага сечения модели из перечисления [ksDynamicCrossSectionStepBuildingTypeEnum](ksdynamiccrosssectionstepbuildingtypeenum.html).  
---|---  
  
Подразделы:

(отсутствуют)
