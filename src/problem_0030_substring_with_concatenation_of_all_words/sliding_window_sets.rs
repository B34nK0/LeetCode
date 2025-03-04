pub struct Solution;

// ------------------------------------------------------ snip ------------------------------------------------------ //

use std::borrow::Borrow;
use std::collections::hash_map::Entry;
use std::collections::{HashMap, VecDeque};
use std::hash::Hash;
use std::iter::FromIterator;

#[derive(PartialEq, Clone)]
struct HashMultiSet<T: Hash + Eq> {
    data: HashMap<T, usize>,
}

impl<T: Hash + Eq> HashMultiSet<T> {
    fn with_capacity(capacity: usize) -> Self {
        Self {
            data: HashMap::with_capacity(capacity),
        }
    }

    fn insert(&mut self, value: T) {
        match self.data.entry(value) {
            Entry::Occupied(entry) => *entry.into_mut() += 1,
            Entry::Vacant(entry) => {
                entry.insert(1);
            }
        }
    }

    fn remove<Q: Hash + Eq + ?Sized>(&mut self, value: &Q)
    where
        T: Borrow<Q>,
    {
        let count = self.data.get_mut(value).unwrap();

        if *count == 1 {
            self.data.remove(value);
        } else {
            *count -= 1;
        }
    }

    fn clear(&mut self) {
        self.data.clear();
    }
}

impl<T: Eq + Hash> FromIterator<T> for HashMultiSet<T> {
    fn from_iter<I: IntoIterator<Item = T>>(iter: I) -> Self {
        let mut result = Self { data: HashMap::new() };

        result.extend(iter);

        result
    }
}

impl<T: Eq + Hash> Extend<T> for HashMultiSet<T> {
    fn extend<I: IntoIterator<Item = T>>(&mut self, iter: I) {
        for item in iter {
            self.insert(item);
        }
    }
}

impl Solution {
    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        let s = s.into_bytes();
        let word_length = words.first().map_or(0, String::len);
        let num_words = words.len();
        let window_length = word_length * num_words;
        let mut result = Vec::new();

        if window_length != 0 && s.len() >= window_length {
            let words = words.iter().map(String::as_bytes).collect::<HashMultiSet<_>>();
            let mut words_cache = HashMultiSet::with_capacity(num_words);

            if s.len() < window_length + word_length {
                result.extend(s.windows(window_length).enumerate().filter_map(|(i, window)| {
                    words_cache.extend(window.chunks_exact(word_length));

                    let r = (words_cache == words).then(|| i as i32);

                    words_cache.clear();

                    r
                }));
            } else {
                let mut cache = VecDeque::with_capacity(word_length);

                result.extend(
                    s.windows(window_length)
                        .enumerate()
                        .take(word_length)
                        .filter_map(|(i, window)| {
                            words_cache.extend(window.chunks_exact(word_length));
                            cache.push_back(words_cache.clone());

                            let r = (words_cache == words).then(|| i as i32);

                            words_cache.clear();

                            r
                        }),
                );

                result.extend(
                    (word_length..)
                        .zip(s.windows(word_length).zip(s.windows(word_length).skip(window_length)))
                        .filter_map(|(i, (obsolete_word, new_word))| {
                            let mut current_words = cache.pop_front().unwrap();

                            current_words.remove(obsolete_word);
                            current_words.insert(new_word);

                            let r = (current_words == words).then(|| i as i32);

                            cache.push_back(current_words);

                            r
                        }),
                );
            }
        }

        result
    }
}

// ------------------------------------------------------ snip ------------------------------------------------------ //

impl super::Solution for Solution {
    fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        Self::find_substring(s, words)
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn test_solution() {
        super::super::tests::run::<super::Solution>();
    }
}
