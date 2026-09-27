// Standard O(1) average design: Vec of values + HashMap<value, HashSet<indices>>.
// Remove any index from the set, swap with the final Vec element, update the swapped element's index set.
