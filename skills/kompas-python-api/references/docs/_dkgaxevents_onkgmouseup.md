# OnKgMouseUp - Кнопка мыши отпущена

[KGAX - ActiveX компонент](kgax.html) > [Интерфейсы](co1725258.html) > [Интерфейс _DKGAX ](_dkgax.html) > [Интерфейс _DKGAX - События ](_dkgaxeventscommon.html) |  Scroll [ [ [ ](_dkgaxevents_onkgmousedblclick.html "К следующему разделу")](_dkgaxeventscommon.html "На уровень выше")](_dkgaxevents_onkgmousedown.html "К предыдущему разделу")  
---|---  
  
Синтаксис Automation:

void OnKgMouseUp ([in]short nButton,

[in]short nShiftState,

[in]long x, [in]long y,

[out]VARIANT_BOOL* proceed );

Входные параметры:

nButton | \- номер кнопки мыши,  
---|---  
nShiftState | \- признак нажатия кнопки Shift,  
x, y | \- координаты мыши.  
  
Выходные параметры:

proceed | \- использовать ли стандартную обработку нажатия кнопки мыши.  
---|---  
  
Примечание:

Приложение может запретить обработку события системой КОМПАС. Для этого переменной proceed нужно присвоить значение FALSE.

Подразделы:

(отсутствуют)
