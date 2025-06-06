/**
 * Time Complexity: O(n * log(n))
 * Space Complexity: O(n)
 * where `n` is the length of the vector `squares`
 */
class Solution {
 private:
  /**
   * <0>: x1 (left)
   * <1>: x2 (right)
   * <3>: delta (1 or -1)
   */
  using x_interval_t = array<int, 3>;

  class SegmentTree {
   public:
    SegmentTree(const vector<int> &values)
    : n_(static_cast<int>(values.size()))
    , values_(values)
    , value_to_index_{}
    , min_cover_length_(tree_size())
    , min_cover_(min_cover_length_.size())
    , lazy_(min_cover_length_.size()) {
      for (int i = 0; i < n_; ++i) {
        value_to_index_[values[i]] = i;
      }
      build_tree(0, 0, n_);
    }
    
    void update(const int left_value, const int right_value, const int delta) {
      const int left = value_to_index_.at(left_value);
      const int right = value_to_index_.at(right_value);
      update_impl(0, 0, n_, left, right, delta);
    }
    
    int query() {
      return query_impl(0, 0, n_, 0, n_ - 1);
    }

   private:
    int tree_size() const {
      return (1 << (static_cast<int>(ceil(log2(n_))) + 1)) - 1;
    }

    void update_impl(const int node, const int begin, const int end, const int left, const int right, const int delta) {
      if (left >= end || right <= begin) {
        return;
      }

      if (left <= begin && end <= right) {
        min_cover_[node] += delta;
        lazy_[node] += delta;
        return;
      }

      push_down(node, begin, end);

      const int left_node = (node << 1) + 1;
      const int right_node = (node << 1) + 2;
      const int mid = begin + ((end - begin) >> 1);

      update_impl(left_node, begin, mid, left, right, delta);
      update_impl(right_node, mid, end, left, right, delta);
      min_cover_[node] = min(min_cover_[left_node], min_cover_[right_node]);
      min_cover_length_[node] = (min_cover_[node] == min_cover_[left_node] ? min_cover_length_[left_node] : 0) +
                                (min_cover_[node] == min_cover_[right_node] ? min_cover_length_[right_node] : 0);
    }

    int query_impl(const int node, const int begin, const int end, const int left, const int right) {
       if (left >= end || right <= begin) {
        return 0;
      }

      if (left <= begin && end <= right) {
        const int total_length = values_[end] - values_[begin];
        if (min_cover_[node] == 0) {
          return total_length - min_cover_length_[node];
        } else {
          return total_length;
        }
      }

      push_down(node, begin, end);

      const int left_node = (node << 1) + 1;
      const int right_node = (node << 1) + 2;
      const int mid = begin + ((end - begin) >> 1);

      return query_impl(left_node, begin, mid, left, right) + query_impl(right_node, mid, right, left, right);
    }

    void push_down(const int node, const int begin, const int end) {
      if (lazy_[node] == 0) {
        return;
      }

      const int left_node = (node << 1) + 1;
      const int right_node = (node << 1) + 2;

      min_cover_[left_node] += lazy_[node];
      lazy_[left_node] += lazy_[node];
      min_cover_[right_node] += lazy_[node];
      lazy_[right_node] += lazy_[node];
      lazy_[node] = 0;
    }

    void build_tree(const int node, const int begin, const int end) {
      if (end - begin == 1) {
        min_cover_length_[node] = end == n_ ? 0 : values_[end] - values_[begin];
        return;
      }

      const int left_node = (node << 1) + 1;
      const int right_node = (node << 1) + 2;
      const int mid = begin + ((end - begin) >> 1);

      build_tree(left_node, begin, mid);
      build_tree(right_node, mid, end);
      min_cover_length_[node] = min_cover_length_[left_node] + min_cover_length_[right_node];
    }

    const int n_;
    const vector<int> &values_;
    unordered_map<int, int> value_to_index_;
    vector<int> min_cover_length_;
    vector<int> min_cover_;
    vector<int> lazy_;
  };
  
 public:
  double separateSquares(const vector<vector<int>> &squares) {
    constexpr int x_i = 0;
    constexpr int y_i = 1;
    constexpr int l_i = 2;
    unordered_map<int, vector<x_interval_t>> y_to_x_intervals;
    vector<int> ys;
    vector<int> xs;
    for (const vector<int> &sqaure : squares) {
      const int x = sqaure[x_i];
      const int y = sqaure[y_i];
      const int l = sqaure[l_i];
      sweep(y_to_x_intervals, ys, y, x, x + l, 1);
      sweep(y_to_x_intervals, ys, y + l, x, x + l, -1);
      xs.emplace_back(x);
      xs.emplace_back(x + l);
    }
    
    sort(ys.begin(), ys.end());
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    SegmentTree segment_tree(xs);
    long long total_area = 0;
    long long double_areas[ys.size() - 1];
    memset(double_areas, 0, sizeof(double_areas));
    int sum_xs[ys.size() - 1];
    memset(sum_xs, 0, sizeof(sum_xs));
    for (size_t i = 0; i + 1 < ys.size(); ++i) {
      const int distance_y = ys[i + 1] - ys[i];
      const vector<x_interval_t> &intervals = y_to_x_intervals[ys[i]];
      for (const auto [x1, x2, delta] : intervals) {
        segment_tree.update(x1, x2, delta);
      }
      const int sum_x = segment_tree.query();
      double_areas[i] = total_area << 1;
      sum_xs[i] = sum_x;
      total_area += static_cast<long long>(distance_y) * sum_x;
    }
    const int index = static_cast<int>(lower_bound(double_areas, double_areas + (ys.size() - 1), total_area) - double_areas) - 1;
    /**
     * (area + sum_x * (ret - y)) * 2 = total_area
     * ret = y + (total_area / 2 - area) / sum_x
     * ret = y + (total_area - 2 * area) / 2 * sum_x
     */
    return ys[index] + (total_area - double_areas[index]) / static_cast<double>(sum_xs[index] << 1);
  }

 private:
  void sweep(unordered_map<int, vector<x_interval_t>> &y_to_x_intervals,
             vector<int> &ys,
             const int y,
             const int x1,
             const int x2,
             const int delta) {
    auto itr = y_to_x_intervals.find(y);
    if (itr == y_to_x_intervals.end()) {
      ys.emplace_back(y);
      itr = y_to_x_intervals.emplace(y, vector<x_interval_t>{}).first;
    }
    itr->second.emplace_back(x_interval_t{x1, x2, delta});
  }
};
