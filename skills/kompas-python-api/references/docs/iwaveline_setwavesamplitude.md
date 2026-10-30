# SetWavesAmplitude - Задать представление амплитуды волн

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Интерфейс IWaveLine ](iwaveline.html) > [IWaveLine - методы ](iwaveline_methods.html) |  Scroll [ [ [ ](bb2356896.html "К следующему разделу")](iwaveline_methods.html "На уровень выше")](iwaveline_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iwaveline.html)

Синтаксис Automation:

BOOL SetWavesAmplitude( BOOL Representation,

double NewVal )

Синтаксис COM:

HRESULT SetWavesAmplitude( BOOL Representation,

double NewVal,

BOOL * Result );

Входные параметры:

Representation | \- TRUE - амплитуда задана в абсолютных значениях, FALSE - в процентах,  
---|---  
NewVal | \- значение амплитуды.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет задать представление амплитуды волн.

Подразделы:

(отсутствуют)
