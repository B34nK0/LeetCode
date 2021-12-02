pub mod brute_force;
pub mod convex_hull;

pub trait Solution {
    fn largest_triangle_area(points: Vec<Vec<i32>>) -> f64;
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use crate::test_utilities::Matrix;

    #[allow(clippy::manual_assert)]
    pub fn run<S: Solution>() {
        let test_cases = [
            (&[[0, 0], [0, 1], [1, 0], [0, 2], [2, 0]] as &dyn Matrix<_>, 2.0),
            (&[[1, 0], [0, 0], [0, 1]], 0.5),
            (&[[8, 10], [2, 7], [9, 2], [4, 10]], 25.5),
            (&[[6, 3], [5, 2], [5, 8], [0, 6]], 15.0),
            (&[[0, 8], [7, 0], [5, 3], [2, 9], [9, 5]], 25.5),
            (&[[9, 0], [0, 2], [3, 1], [10, 8]], 37.0),
            (
                &[
                    [25, 30],
                    [48, -27],
                    [-44, 29],
                    [-37, -21],
                    [38, 33],
                    [-43, -13],
                    [21, -24],
                    [17, -31],
                    [-16, -1],
                    [-25, 18],
                    [4, 0],
                    [-4, 19],
                    [-23, 45],
                    [18, 35],
                    [48, -11],
                    [-39, -40],
                    [-35, -4],
                    [41, -15],
                    [30, 50],
                    [28, -22],
                    [-17, -18],
                    [11, 7],
                    [-8, 28],
                    [-10, -33],
                    [28, -46],
                    [22, 18],
                    [17, 26],
                    [-22, 50],
                    [17, -38],
                    [20, -23],
                    [-19, 4],
                    [-49, 4],
                    [35, -22],
                    [-32, 23],
                    [-18, -41],
                    [21, 13],
                    [4, 48],
                    [-22, -46],
                    [3, -30],
                    [38, 26],
                ],
                3804.5,
            ),
        ];

        for (points, expected) in test_cases {
            approx::assert_ulps_eq!(S::largest_triangle_area(points.to_vec()), expected);
        }
    }
}
