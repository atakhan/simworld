#include "heightmap.h"

HeightMap::HeightMap(int w, int h)
    : width_(w)
    , height_(h)
    {}

int HeightMap::GetRandomIntBetween(int min, int max) {
    return min + (rand() % static_cast<int>(max - min + 1));
}

void HeightMap::Generate() {
    GenerateNoise();
}

void HeightMap::GenerateNoise() {
    int from = MIN_HEIGHT;
    int to = MAX_HEIGHT;
    int tiles_count = width_ * height_;
    for (int i = 0; i < width_; i++) {
        for (int j = 0; j < height_; j++) {
            int peak_generate_probabilty = GetRandomIntBetween(0, tiles_count);
            if (peak_generate_probabilty <= PEAKS_PREVALENCE) {
                from = MAX_HEIGHT - 100;
                to = MAX_HEIGHT;
            } else {
                from = MIN_HEIGHT;
                to = MIN_HEIGHT;
            }
            int rand_val = GetRandomIntBetween(from, to);
            data_.push_back(rand_val);
        }
    }
}

void HeightMap::UpdateNW(int index) {
    if (index > width_) {
        int nw_index = index - width_ - 1;
        int currentCell = data_.at(index);
        int nw_cell = data_.at(nw_index);
        int diff = currentCell - nw_cell;
        if (diff < -ALLOW_DIFF) {
            data_.at(nw_index) = nw_cell - diff + ALLOW_DIFF;
        }
        if (diff > ALLOW_DIFF) {
            data_.at(nw_index) = nw_cell + diff - ALLOW_DIFF;
        }
    }
}

void HeightMap::UpdateN(int index) {
    if (index > width_) {
        int n_index = index - width_;
        int currentCell = data_.at(index);
        int nw_cell = data_.at(n_index);
        int diff = currentCell - nw_cell;
        if (diff < -ALLOW_DIFF) {
            data_.at(n_index) = nw_cell - diff + ALLOW_DIFF;
        }
        if (diff > ALLOW_DIFF) {
            data_.at(n_index) = nw_cell + diff - ALLOW_DIFF;
        }
    }
}

void HeightMap::UpdateNE(int index) {
    if ((index > width_) && ((index + 1) % width_ != 0)) {
        int ne_index = index - width_ + 1;
        int currentCell = data_.at(index);
        int nw_cell = data_.at(ne_index);
        int diff = currentCell - nw_cell;
        if (diff < -ALLOW_DIFF) {
            data_.at(ne_index) = nw_cell - diff + ALLOW_DIFF;
        }
        if (diff > ALLOW_DIFF) {
            data_.at(ne_index) = nw_cell + diff - ALLOW_DIFF;
        }
    }
}

void HeightMap::UpdateE(int index) {
    if (((index + 1) % width_ != 0)) {
        int e_index = index + 1;
        int currentCell = data_.at(index);
        int nw_cell = data_.at(e_index);
        int diff = currentCell - nw_cell;
        if (diff < -ALLOW_DIFF) {
            data_.at(e_index) = nw_cell - diff + ALLOW_DIFF;
        }
        if (diff > ALLOW_DIFF) {
            data_.at(e_index) = nw_cell + diff - ALLOW_DIFF;
        }
    }
}

void HeightMap::UpdateSE(int index) {
    if (((index + 1) % width_ != 0) && ((index + width_ + 1) < data_.size())) {
        int se_index = index + width_ + 1;
        int currentCell = data_.at(index);
        int nw_cell = data_.at(se_index);
        int diff = currentCell - nw_cell;
        if (diff < -ALLOW_DIFF) {
            data_.at(se_index) = nw_cell - diff + ALLOW_DIFF;
        }
        if (diff > ALLOW_DIFF) {
            data_.at(se_index) = nw_cell + diff - ALLOW_DIFF;
        }
    }
}

void HeightMap::UpdateS(int index) {
    if ((index + width_ + 1) < data_.size()) {
        int s_index = index + width_;
        int currentCell = data_.at(index);
        int nw_cell = data_.at(s_index);
        int diff = currentCell - nw_cell;
        if (diff < -ALLOW_DIFF) {
            data_.at(s_index) = nw_cell - diff + ALLOW_DIFF;
        }
        if (diff > ALLOW_DIFF) {
            data_.at(s_index) = nw_cell + diff - ALLOW_DIFF;
        }
    }
}

void HeightMap::UpdateSW(int index) {
    if (((index - 1) % width_ != 0) && (index < (data_.size() - width_))) {
        int se_index = index + width_;
        int currentCell = data_.at(index);
        int nw_cell = data_.at(se_index);
        int diff = currentCell - nw_cell;
        if (diff < -ALLOW_DIFF) {
            data_.at(se_index) = nw_cell - diff + ALLOW_DIFF;
        }
        if (diff > ALLOW_DIFF) {
            data_.at(se_index) = nw_cell + diff - ALLOW_DIFF;
        }
    }
}

void HeightMap::UpdateNeighbors(int index) {
    UpdateNW(index);
    UpdateN(index);
    UpdateNE(index);
    UpdateE(index);
    UpdateSE(index);
    UpdateS(index);
    UpdateSW(index);
}

void HeightMap::MakeErosion() {
    int index = 0;
    
    for (int i = 0; i < width_; i++) {
        for (int j = 0; j < height_; j++) {
            if (data_.at(index) > 200) {
                UpdateNeighbors(index);
            }
            index++;
        }
    }    
}

void HeightMap::filterPeaks() {
    int index = 0;
    bool in_process = true;
    for (int i = 0; i < width_; i++) {
        for (int j = 0; j < height_; j++) {
            if (data_.at(index) < 255) {
                data_.at(index) = 0;
            }
            index++;
        }
    }
}
