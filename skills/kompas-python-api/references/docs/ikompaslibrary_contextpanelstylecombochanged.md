# ContextPanelStyleComboChanged - Изменение значения в стилевом комбобоксе всплывающей панели

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс IKompasLibrary ](ikompaslibrary.html) > [IKompasLibrary - методы ](ikompaslibrary_methods.html) |  Scroll [ [ [ ](ikompaslibrary_createmacrofromsample.html "К следующему разделу")](ikompaslibrary_methods.html "На уровень выше")](ikompaslibrary_beginunloadlibrary.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompaslibrary.html)

Синтаксис:

HRESULT ContextPanelStyleComboChanged( BSTR StyleComboID, long styleType, long newValue, VARIANT_BOOL * Result );

Входные параметры:

StyleComboID | \- cтроковый идентификатор стилевого комбобокса описанного в манифесте библиотеки,  
---|---  
styleType | \- тип стилевого комбобокса из перечисления [ControlTypeEnum](controltypeenum.html).  
  
Возвращаемое значение:

Не используется

Примечание:

Функция вызывается, если приложение подтвердило, что поддерживает работу данного метода (см. [IKompasLibrary::IsFunctionEnable](ikompaslibrary_isfunctionenable.html)).

Подразделы:

(отсутствуют)
