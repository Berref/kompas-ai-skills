#ifndef __LIBTOOL_H
#include <libtool.h>
#endif

#include "CPropMen.h"
#include <libhppar.h>


#if !defined(_IFUNC)
# define _IFUNC STDMETHODCALLTYPE
#endif


////////////////////////////////////////////////////////////////////////////////
//
// Класс для отрисовки фигур через API7
//
////////////////////////////////////////////////////////////////////////////////
class Api7Draw : public PropertyManagerObject
{
  enum class DrawType
  { 
    DrawRect     = ID_Button1,
    DrawCircle   = ID_Button2,
    DrawTreangle = ID_Button3,
  };

  ksAPI7::IDrawingGroupPtr  m_phantomGroup;
  ksAPI7::IProcessPtr       m_Process;

  DrawType                  m_PhantomType = DrawType::DrawRect;  // Тип фантома

  reference                 m_refMacr;  // Референсе макро
public:
  // Построение геометрии
  void GetGroup        ();
  // Изменение фантома
  void RedrawPhantom   ();
  // Отрисовка фантома
  void DrawPhantom     ( double x, double y, double angle, BOOL dynamic );
  // Отображение кнопок спецпанели
  void ShowControls    ();
  // Изменение положения 
  BOOL PlacementChanged( double x, double y, double angle, BOOL dynamic );
  // Запуска процесса
  void ChoicePlacement ();

  // prButtonClick         - Нажатие кнопки.
  BOOL ButtonClick ( long buttonID );
  // prButtonUpdate        - Установка состояния кнопки спецпанели.
  BOOL ButtonUpdate( long buttonID, long * check, VARIANT_BOOL  * _enable );

};

