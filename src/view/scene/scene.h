#ifndef A1_MAZE_SRC_VIEW_SCENE_SCENE_H_
#define A1_MAZE_SRC_VIEW_SCENE_SCENE_H_

#include <QGraphicsItemGroup>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QWidget>

#include "../../controller/controller.h"

namespace s21 {

class Scene : public QGraphicsView {
  Q_OBJECT
 public:
  Scene(MazeController *maze_controller, QWidget *parent = nullptr);
  void PaintMaze(int way);

 private:
  void DeleteItemsFromGroup(QGraphicsItemGroup *group_1);
  void PaintMazeBody(std::vector<std::vector<int>> right,
                     std::vector<std::vector<int>> bottom, double width_step,
                     double height_step);
  void PaintWay(std::vector<std::vector<int>> way_v, double width_step,
                double height_step);

  QGraphicsScene *scene_;
  QGraphicsItemGroup *group_1_;
  QGraphicsItemGroup *group_2_;
  s21::MazeController *maze_controller_;
};

}  // namespace s21

#endif  // A1_MAZE_SRC_VIEW_SCENE_SCENE_H_
