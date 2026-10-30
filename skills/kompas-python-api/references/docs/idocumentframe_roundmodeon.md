# RoundModeOn - Состояние режима округления линейных величин до значений, кратных шагу курсора

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IDocumentFrame ](idocumentframe.html) > [IDocumentFrame - свойства ](idocumentframe_props.html) |  Scroll [ [ [ ](idocumentframe_methods.html "К следующему разделу")](idocumentframe_props.html "На уровень выше")](idocumentframe_regime.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocumentframe.html)

Тип данных: BOOL

Синтаксис Automation:

RoundModeOn = Object.RoundModeOn( ) | Получить свойство ([* ](1.html))  
---|---  
RoundModeOn = Object.GetRoundModeOn() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_RoundModeOn( &RoundModeOn ) | Получить свойство  
---|---  
  
Примечание

При включенном режиме значения параметров округляются до ближайшего значения, кратного текущему шагу курсора [IDocumentFrame::CurrentCursorStep](idocumentframe_currentcursorstep.html).

Подразделы:

(отсутствуют)
