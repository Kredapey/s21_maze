#include "scene.h"

namespace s21 {

Scene::Scene(s21::MazeController *maze_controller, QWidget *parent)
    : QGraphicsView{parent}, maze_controller_(maze_controller) {
  this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setAlignment(Qt::AlignCenter);
  this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  QBrush whiteBrush(Qt::white);
  QGraphicsView::setBackgroundBrush(whiteBrush);
  this->setFixedHeight(500);
  this->setFixedWidth(500);
  scene_ = new QGraphicsScene();
  this->setScene(scene_);
  group_1_ = new QGraphicsItemGroup();
  group_2_ = new QGraphicsItemGroup();
  scene_->addItem(group_1_);
  scene_->addItem(group_2_);
}

void Scene::PaintMaze(int way) {
  std::vector<std::vector<int>> right = maze_controller_->GetRight();
  std::vector<std::vector<int>> bottom = maze_controller_->GetBottom();
  std::vector<std::vector<int>> way_v = maze_controller_->GetWay();
  this->DeleteItemsFromGroup(group_1_);
  this->DeleteItemsFromGroup(group_2_);
  int width = this->width();
  int height = this->height();
  double width_step = 0;
  double height_step = 0;
  if (right.size() > 0 && right[0].size() > 0) {
    width_step = width / (double)right[0].size();
    height_step = height / (double)right.size();
  }
  scene_->setSceneRect(0, 0, width, height);

  PaintMazeBody(right, bottom, width_step, height_step);
  if (way == 1) {
    PaintWay(way_v, width_step, height_step);
  }
}

void Scene::PaintMazeBody(std::vector<std::vector<int>> right,
                          std::vector<std::vector<int>> bottom,
                          double width_step, double height_step) {
  QPen penBlack(Qt::black);
  penBlack.setWidth(2);
  for (unsigned long i = 0; i < right.size(); ++i) {
    for (unsigned long j = 0; j < right[i].size(); ++j) {
      if (right[i][j] == 1) {
        group_1_->addToGroup(
            scene_->addLine((width_step * j) + width_step, height_step * i,
                            (width_step * j) + width_step,
                            height_step * i + height_step, penBlack));
      }
      if (bottom[i][j] == 1) {
        group_1_->addToGroup(
            scene_->addLine(width_step * j, height_step * i + height_step,
                            width_step * j + width_step,
                            height_step * i + height_step, penBlack));
      }
    }
  }
}

void Scene::PaintWay(std::vector<std::vector<int>> way_v, double width_step,
                     double height_step) {
  QPen penRed(Qt::red);
  penRed.setWidth(2);
  unsigned long prev_i = 0;
  unsigned long prev_j = 0;
  int prev_cell = 0;
  for (unsigned long i = 0; i < way_v.size(); i++) {
    for (unsigned long j = 0; j < way_v[i].size(); j++) {
      if (way_v[i][j] == 1) {
        prev_i = i;
        prev_j = j;
        prev_cell = 1;
        break;
      }
    }
  }
  while (prev_cell != maze_controller_->GetCountWay()) {
    if (prev_j < way_v[prev_i].size() - 1 &&
        way_v[prev_i][prev_j + 1] == prev_cell + 1) {
      group_2_->addToGroup(
          scene_->addLine(width_step * prev_j + width_step / 2,
                          height_step * prev_i + height_step / 2,
                          width_step * prev_j + width_step / 2 + width_step,
                          height_step * prev_i + height_step / 2, penRed));
      prev_j = prev_j + 1;
    } else if (prev_j > 0 && way_v[prev_i][prev_j - 1] == prev_cell + 1) {
      group_2_->addToGroup(
          scene_->addLine(width_step * prev_j + width_step / 2,
                          height_step * prev_i + height_step / 2,
                          width_step * prev_j + width_step / 2 - width_step,
                          height_step * prev_i + height_step / 2, penRed));
      prev_j = prev_j - 1;
    } else if (prev_i < way_v.size() - 1 &&
               way_v[prev_i + 1][prev_j] == prev_cell + 1) {
      group_2_->addToGroup(scene_->addLine(
          width_step * prev_j + width_step / 2,
          height_step * prev_i + height_step / 2,
          width_step * prev_j + width_step / 2,
          height_step * prev_i + height_step / 2 + height_step, penRed));
      prev_i = prev_i + 1;
    } else if (prev_i > 0 && way_v[prev_i - 1][prev_j] == prev_cell + 1) {
      group_2_->addToGroup(scene_->addLine(
          width_step * prev_j + width_step / 2,
          height_step * prev_i + height_step / 2,
          width_step * prev_j + width_step / 2,
          height_step * prev_i + height_step / 2 - height_step, penRed));
      prev_i = prev_i - 1;
    }
    prev_cell += 1;
  }
}

void Scene::DeleteItemsFromGroup(QGraphicsItemGroup *group) {
  foreach (QGraphicsItem *item, scene_->items(group->boundingRect())) {
    if (item->group() == group) {
      delete item;
    }
  }
}

}  // namespace s21
